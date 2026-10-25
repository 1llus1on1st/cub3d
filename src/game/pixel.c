#include "cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = game->addr + y * game->line_len + x * (game->bpp / 8);
	*(unsigned int *)dst = color;
}