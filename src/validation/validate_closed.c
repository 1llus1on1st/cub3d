#include "cub3d.h"

static char	cell_at(t_scene *scene, int y, int x)
{
	if (y < 0 || y >= scene->map.height)
		return (' ');
	if (x < 0 || x >= scene->map.row_len[y])
		return (' ');
	return (scene->map.grid[y][x]);
}

static int	is_open_cell(char c)
{
	return (c != '1' && c != ' ');
}

static int	is_leaky(t_scene *scene, int y, int x)
{
	return (cell_at(scene, y - 1, x) == ' '
		|| cell_at(scene, y + 1, x) == ' '
		|| cell_at(scene, y, x - 1) == ' '
		|| cell_at(scene, y, x + 1) == ' ');
}

static void	check_row(t_scene *scene, int y)
{
	int	x;

	x = 0;
	while (x < scene->map.row_len[y])
	{
		if (is_open_cell(scene->map.grid[y][x]) && is_leaky(scene, y, x))
			error_exit("map is not closed", scene);
		x++;
	}
}

void	validate_closed(t_scene *scene)
{
	int	y;

	y = 0;
	while (y < scene->map.height)
	{
		check_row(scene, y);
		y++;
	}
}
