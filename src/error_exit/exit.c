#include "cub3d.h"

static void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (map->grid[i])
		free(map->grid[i++]);
	free(map->grid);
	free(map->row_len);
}

static void	free_raw_lines(t_scene *scene)
{
	int	i;
	int	end;

	if (!scene->raw_lines)
		return ;
	end = scene->map_start;
	if (end < 0)
	{
		end = 0;
		while (scene->raw_lines[end])
			end++;
	}
	i = 0;
	while (i < end)
		free(scene->raw_lines[i++]);
	free(scene->raw_lines);
}

void	error_exit(char *msg, t_scene *scene)
{
	if (scene)
	{
		free_raw_lines(scene);
		free(scene->path_no);
		free(scene->path_so);
		free(scene->path_we);
		free(scene->path_ea);
		free_map(&scene->map);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
