#include "cub3d.h"

static int	count_lines(char *raw)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (raw[i])
	{
		if (raw[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && raw[i - 1] != '\n')
		count++;
	return (count);
}

static void	free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

char	**split_lines(char *raw)
{
	char	**lines;
	int		i;
	int		start;
	int		line_i;

	lines = malloc(sizeof(char *) * (count_lines(raw) + 1));
	if (!lines)
		return (NULL);
	i = 0;
	start = 0;
	line_i = 0;
	while (raw[i])
	{
		if (raw[i] == '\n')
		{
			lines[line_i] = ft_substr(raw, start, i - start);
			if (!lines[line_i])
				return (free_lines(lines, line_i), NULL);
			line_i++;
			start = i + 1;
		}
		i++;
	}
	if (start < i)
	{
		lines[line_i] = ft_substr(raw, start, i - start);
		if (!lines[line_i])
			return (free_lines(lines, line_i), NULL);
		line_i++;
	}
	lines[line_i] = NULL;
	return (lines);
}
