#include "cub3d.h"

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0');
}

int	skip_blank_lines(char **lines, int i)
{
	while (lines[i] && is_blank_line(lines[i]))
		i++;
	return (i);
}
