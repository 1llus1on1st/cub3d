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
		digits++;
		s++;
	}
	if (digits == 0 || value > 255)
		return (NULL);
	*out = value;
	return (s);
}

int	parse_color(char *content, t_color *color)
{
	content = parse_component(content, &color->r);
	if (!content || *content != ',')
		return (0);
	content = parse_component(content + 1, &color->g);
	if (!content || *content != ',')
		return (0);
	content = parse_component(content + 1, &color->b);
	if (!content || *content != '\0')
		return (0);
	return (1);
}