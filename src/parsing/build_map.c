#include "cub3d.h"

static int	last_map_line(char **lines, int map_start, t_scene *scene)
{
	int	last;
	int	i;

	last = -1;
	i = map_start;
	while (lines[i])
	{
		if (!is_blank_line(lines[i]))
			last = i;
		i++;
	}
	if (last < 0)
		error_exit("map is empty", scene);
	return (last);
}

static int	trim_map(char **lines, int map_start, t_scene *scene)
{
	int	last;
	int	i;

	last = last_map_line(lines, map_start, scene);
	i = map_start;
	while (i < last)
	{
		if (is_blank_line(lines[i]))
			error_exit("blank line inside map", scene);
		i++;
	}
	i = last + 1;
	while (lines[i])
		free(lines[i++]);
	lines[last + 1] = NULL;
	return (last - map_start + 1);
}

void	build_map(char **lines, int map_start, t_scene *scene)
{
	int	count;
	int	i;

	count = trim_map(lines, map_start, scene);
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
