#include "cub3d.h"

static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	validate_map_chars(t_scene *scene)
{
	int	y;
	int	x;

	y = 0;
	while (y < scene->map.height)
	{
		x = 0;
		while (x < scene->map.row_len[y])
		{
			if (!is_map_char(scene->map.grid[y][x]))
				error_exit("invalid character in map", scene);
			x++;
		}
		y++;
	}
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	scan_row(t_scene *scene, int y, int count)
{
	int	x;

	x = 0;
	while (x < scene->map.row_len[y])
	{
		if (is_player_char(scene->map.grid[y][x]))
		{
			scene->player_x = x;
			scene->player_y = y;
			scene->player_dir = scene->map.grid[y][x];
			count++;
		}
		x++;
	}
	return (count);
}

void	validate_player(t_scene *scene)
{
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < scene->map.height)
	{
		count = scan_row(scene, y, count);
		y++;
	}
	if (count != 1)
		error_exit("map must contain exactly one player start", scene);
}
