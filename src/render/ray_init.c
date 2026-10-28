#include "cub3d.h"

static double	delta_dist(double dir)
{
	if (dir == 0)
		return (1e30);
	return (fabs(1.0 / dir));
}

static void	init_step_x(t_player *p, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (p->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_x;
	}
}

static void	init_step_y(t_player *p, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (p->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_y;
	}
}

void	init_ray(t_game *game, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2.0 * x / WIN_W - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->delta_x = delta_dist(ray->dir_x);
	ray->delta_y = delta_dist(ray->dir_y);
	init_step_x(&game->player, ray);
	init_step_y(&game->player, ray);
}
