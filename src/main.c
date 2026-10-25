#include "cub3d.h"

static int	has_cub_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	return (ft_strncmp(&path[len - 4], ".cub", 4) == 0);
}

static void	load_scene(t_game *game, char *path)
{
	char	*raw;
	char	**lines;
	int		map_start;
	int		i;

	raw = load_and_read(path);
	lines = split_lines(raw);
	free(raw);
	if (!lines)
		error_exit("could not split map file into lines", NULL);
	game->scene.map_start = -1;
	game->scene.raw_lines = lines;
	map_start = parse_headers(lines, &game->scene);
	build_map(lines, map_start, &game->scene);
	validate_map(&game->scene);
	i = 0;
	while (i < map_start)
		free(lines[i++]);
	free(lines);
	game->scene.raw_lines = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("usage: ./cub3d <map.cub>", NULL);
	if (!has_cub_extension(argv[1]))
		error_exit("map file must have a .cub extension", NULL);
	ft_bzero(&game, sizeof(t_game));
	load_scene(&game, argv[1]);
	init_game(&game);
	// printf("player: x=%d y=%d dir=%c\n",
	// 	game.scene.player_x, game.scene.player_y, game.scene.player_dir);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
