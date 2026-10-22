#include "cub3d.h"

static char	*parse_component(char *s, int *out)
{
	int	value;
	int	digits;

	value = 0;
	digits = 0;
	while (*s >= '0' && *s <= '9')
	{
		value = value * 10 + (*s - '0');
		if (value > 255)
			return (NULL);
		digits++;
		s++;
	}
	if (digits == 0)
		return (NULL);
	*out = value;
	return (s);
}

static char	*skip_spaces(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

static char	*next_component(char *s, int *out)
{
	s = skip_spaces(s);
	s = parse_component(s, out);
	if (!s)
		return (NULL);
	return (skip_spaces(s));
}

int	parse_color(char *content, t_color *color)
{
	content = next_component(content, &color->r);
	if (!content || *content != ',')
		return (0);
	content = next_component(content + 1, &color->g);
	if (!content || *content != ',')
		return (0);
	content = next_component(content + 1, &color->b);
	if (!content || *content != '\0')
		return (0);
	return (1);
}
