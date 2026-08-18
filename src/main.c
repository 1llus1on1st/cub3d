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

	if (argc != 2)
		error_exit("usage: ./cub3d <map.cub>");
	if (!has_cub_extension(argv[1]))
		error_exit("map file must have a .cub extension");
	raw = load_and_read(argv[1]);
	lines = split_lines(raw);
	free(raw);
	if (!lines)
		error_exit("could not split map file into lines");
	ft_bzero(&scene, sizeof(t_scene));
	parse_headers(lines, &scene);
	return (0);
}
