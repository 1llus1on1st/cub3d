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

static int	store_path(char **field, int *seen, char *content, t_scene *scene)
{
	if (*seen)
		error_exit("duplicate texture identifier", scene);
	*field = ft_strdup(content);
	if (!*field)
		error_exit("allocation failed", scene);
	*seen = 1;
	return (1);
}

static int	store_color(t_color *field, int *seen, char *content,
		t_scene *scene)
{
	if (*seen)
		error_exit("duplicate color identifier", scene);
	if (!parse_color(content, field))
		error_exit("invalid color format", scene);
	*seen = 1;
	return (1);
}

static int	dispatch_header(char *line, t_scene *scene, t_seen *seen)
{
	char	*content;

	content = match_header(line, "NO");
	if (content)
		return (store_path(&scene->path_no, &seen->no, content, scene));
	content = match_header(line, "SO");
	if (content)
		return (store_path(&scene->path_so, &seen->so, content, scene));
	content = match_header(line, "WE");
	if (content)
		return (store_path(&scene->path_we, &seen->we, content, scene));
	content = match_header(line, "EA");
	if (content)
		return (store_path(&scene->path_ea, &seen->ea, content, scene));
	content = match_header(line, "F");
	if (content)
		return (store_color(&scene->floor_color, &seen->f, content, scene));
	content = match_header(line, "C");
	if (content)
		return (store_color(&scene->ceiling_color, &seen->c, content, scene));
	return (0);
}

int	parse_headers(char **lines, t_scene *scene)
{
	t_seen	seen;
	int		i;

	ft_bzero(&seen, sizeof(t_seen));
	i = skip_blank_lines(lines, 0);
	while (lines[i] && dispatch_header(lines[i], scene, &seen))
		i = skip_blank_lines(lines, i + 1);
	if (!seen.no || !seen.so || !seen.we || !seen.ea || !seen.f || !seen.c)
		error_exit("missing scene element(s)", scene);
	return (i);
}
