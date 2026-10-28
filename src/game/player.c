#include "cub3d.h"

static void	set_vectors(t_player *p, double dx, double dy)
{
	p->dir_x = dx;
	p->dir_y = dy;
	p->plane_x = -dy * FOV_PLANE;
	p->plane_y = dx * FOV_PLANE;
}

void	init_player(t_game *game)
{
	t_player	*p;
	char		c;

	p = &game->player;
	c = game->scene.player_dir;
	p->pos_x = game->scene.player_x + 0.5;
	p->pos_y = game->scene.player_y + 0.5;
	if (c == 'N')
		set_vectors(p, 0, -1);
	else if (c == 'S')
		set_vectors(p, 0, 1);
	else if (c == 'E')
		set_vectors(p, 1, 0);
	else
		set_vectors(p, -1, 0);
}
