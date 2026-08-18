#include "cub3d.h"

static int	has_cub_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	return (ft_strncmp(&path[len - 4], ".cub", 4) == 0);
}

int	main(int argc, char **argv)
{
	char	*raw;
	char	**lines;
	t_scene	scene;
	int		map_start;
	int		i;

	if (argc != 2)
		error_exit("usage: ./cub3d <map.cub>", NULL);
	if (!has_cub_extension(argv[1]))
		error_exit("map file must have a .cub extension", NULL);
	raw = load_and_read(argv[1]);
	lines = split_lines(raw);
	free(raw);
	if (!lines)
		error_exit("could not split map file into lines", NULL);
	ft_bzero(&scene, sizeof(t_scene));
	scene.map_start = -1;
	scene.raw_lines = lines;
	map_start = parse_headers(lines, &scene);
	build_map(lines, map_start, &scene);
	i = 0;
	while (i < map_start)
		free(lines[i++]);
	free(lines);
	scene.raw_lines = NULL;
	return (0);
}
