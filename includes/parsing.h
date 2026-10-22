#ifndef PARSING_H
# define PARSING_H

char	*load_and_read(char *path);
char	*ft_strjoin_free(char *s1, char *s2);
char	**split_lines(char *raw);
int		parse_headers(char **lines, t_scene *scene);
int		parse_color(char *content, t_color *color);
void	build_map(char **lines, int map_start, t_scene *scene);
int		is_blank_line(char *line);
int		skip_blank_lines(char **lines, int i);

#endif