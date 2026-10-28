#ifndef TYPES_H
# define TYPES_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	**grid;
	int		*row_len;
	int		width;
	int		height;
}	t_map;

typedef struct s_scene
{
	t_map	map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	t_color	floor_color;
	t_color	ceiling_color;
	int		player_x;
	int		player_y;
	char	player_dir;
	char	**raw_lines;
	int		map_start;
}	t_scene;

typedef struct s_seen
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_seen;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		side;
	double	dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_scene		scene;
	t_player	player;
}	t_game;

#endif
