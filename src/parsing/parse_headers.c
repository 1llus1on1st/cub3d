#include "cub3d.h"

static char	*match_header(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if (ft_strncmp(line, id, len) != 0)
		return (NULL);
	if (line[len] != ' ')
		return (NULL);
	while (line[len] == ' ')
		len++;
	return (&line[len]);
}

static int	store_path(char **field, int *seen, char *content)
{
	if (*seen)
		error_exit("duplicate texture identifier");
	*field = ft_strdup(content);
	if (!*field)
		error_exit("allocation failed");
	*seen = 1;
	return (1);
}

static int	store_color(t_color *field, int *seen, char *content)
{
	if (*seen)
		error_exit("duplicate color identifier");
	if (!parse_color(content, field))
		error_exit("invalid color format");
	*seen = 1;
	return (1);
}

static int	dispatch_header(char *line, t_scene *scene, t_seen *seen)
{
	char	*content;

	if ((content = match_header(line, "NO")))
		return (store_path(&scene->path_no, &seen->no, content));
	if ((content = match_header(line, "SO")))
		return (store_path(&scene->path_so, &seen->so, content));
	if ((content = match_header(line, "WE")))
		return (store_path(&scene->path_we, &seen->we, content));
	if ((content = match_header(line, "EA")))
		return (store_path(&scene->path_ea, &seen->ea, content));
	if ((content = match_header(line, "F")))
		return (store_color(&scene->floor_color, &seen->f, content));
	if ((content = match_header(line, "C")))
		return (store_color(&scene->ceiling_color, &seen->c, content));
	return (0);
}

int	parse_headers(char **lines, t_scene *scene)
{
	t_seen	seen;
	int		i;

	ft_bzero(&seen, sizeof(t_seen));
	i = 0;
	while (lines[i] && lines[i][0] == '\0')
		i++;
	while (lines[i] && dispatch_header(lines[i], scene, &seen))
	{
		i++;
		while (lines[i] && lines[i][0] == '\0')
			i++;
	}
	if (!seen.no || !seen.so || !seen.we || !seen.ea || !seen.f || !seen.c)
		error_exit("missing scene element(s)");
	return (i);
}