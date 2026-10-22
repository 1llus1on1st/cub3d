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

static int	fill_lines(char **lines, char *raw)
{
	int	i;
	int	start;
	int	n;

	i = 0;
	start = 0;
	n = 0;
	while (raw[i] || start < i)
	{
		if (raw[i] == '\n' || !raw[i])
		{
			lines[n] = ft_substr(raw, start, i - start);
			if (!lines[n])
				return (free_lines(lines, n), -1);
			n++;
			start = i + 1;
		}
		if (raw[i])
			i++;
	}
	lines[n] = NULL;
	return (n);
}

char	**split_lines(char *raw)
{
	char	**lines;

	lines = malloc(sizeof(char *) * (count_lines(raw) + 1));
	if (!lines)
		return (NULL);
	if (fill_lines(lines, raw) < 0)
		return (NULL);
	return (lines);
}
