#include "cub3d.h"

static char	*reader(int file)
{
	char	*res;
	char	buffer[BUFFER_SIZE];
	int		r;

	r = 1;
	res = NULL;
	while (r > 0)
	{
		r = read(file, buffer, BUFFER_SIZE - 1);
		if (r < 0)
			return (free(res), NULL);
		buffer[r] = '\0';
		res = ft_strjoin_free(res, buffer);
		if (!res)
			return (NULL);
	}
	return (res);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined;
	char	*res;
	char	*s1_head;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (free(s1), NULL);
	res = joined;
	s1_head = s1;
	while (*s1 != '\0')
		*(joined++) = *(s1++);
	while (*s2 != '\0')
		*(joined++) = *(s2++);
	*joined = '\0';
	free (s1_head);
	return (res);
}

char	*load_and_read(char *path)
{
	int		fd;
	char	*raw;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("could not open map file");
	raw = reader(fd);
	close(fd);
	if (!raw)
		error_exit("could not read map file");
	return (raw);
}
