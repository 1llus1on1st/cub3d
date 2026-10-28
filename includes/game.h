#ifndef GAME_H
# define GAME_H

# include "types.h"

# define WIN_W 1024
# define WIN_H 768
# define KEY_ESC 53
# define FOV_PLANE 0.66
# define MIN_DIST 0.001

void	init_game(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
int		close_game(t_game *game);
int		key_press(int keycode, t_game *game);
void	setup_hooks(t_game *game);
void	init_player(t_game *game);

#endif