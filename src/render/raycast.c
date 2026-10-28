#include "cub3d.h"

static int	is_wall(t_scene *scene, int x, int y)
{
	if (y < 0 || y >= scene->map.height)
		return (1);
	if (x < 0 || x >= scene->map.row_len[y])
		return (1);
	return (scene->map.grid[y][x] == '1' || scene->map.grid[y][x] == ' ');
}

static void	run_dda(t_scene *scene, t_ray *ray)
{
	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(scene, ray->map_x, ray->map_y))
			return ;
	}
}

static void	set_draw_range(t_ray *ray)
{
	double	dist;

	dist = ray->dist;
	if (dist < MIN_DIST)
		dist = MIN_DIST;
	ray->line_height = (int)(WIN_H / dist);
	ray->draw_start = WIN_H / 2 - ray->line_height / 2;
	ray->draw_end = WIN_H / 2 + ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}

void	cast_ray(t_game *game, int x, t_ray *ray)
{
	init_ray(game, x, ray);
	run_dda(&game->scene, ray);
	if (ray->side == 0)
		ray->dist = ray->side_x - ray->delta_x;
	else
		ray->dist = ray->side_y - ray->delta_y;
	set_draw_range(ray);
}
