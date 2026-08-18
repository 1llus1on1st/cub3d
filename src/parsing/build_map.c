#include "cub3d.h"

void	build_map(char **lines, int map_start, t_scene *scene)
{
	int	count;
	int	i;

	count = 0;
	while (lines[map_start + count])
		count++;
	if (count == 0)
		error_exit("map is empty", scene);
	scene->map.grid = ft_calloc(count + 1, sizeof(char *));
	if (!scene->map.grid)
		error_exit("allocation failed", scene);
	scene->map.row_len = malloc(sizeof(int) * count);
	if (!scene->map.row_len)
		error_exit("allocation failed", scene);
	scene->map.width = 0;
	i = 0;
	while (i < count)
	{
		scene->map.grid[i] = lines[map_start + i];
		scene->map.row_len[i] = ft_strlen(scene->map.grid[i]);
		if (scene->map.row_len[i] > scene->map.width)
			scene->map.width = scene->map.row_len[i];
		i++;
	}
	scene->map.height = count;
	scene->map_start = map_start;
}

