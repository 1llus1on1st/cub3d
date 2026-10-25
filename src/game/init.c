#include "cub3d.h"

static void	init_fail(t_game *game, char *msg)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	error_exit(msg, &game->scene);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		init_fail(game, "mlx_init failed");
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (!game->win)
		init_fail(game, "mlx_new_window failed");
	game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (!game->img)
		init_fail(game, "mlx_new_image failed");
	game->addr = mlx_get_data_addr(game->img, &game->bpp,
			&game->line_len, &game->endian);
	if (!game->addr)
		init_fail(game, "mlx_get_data_addr failed");
}
