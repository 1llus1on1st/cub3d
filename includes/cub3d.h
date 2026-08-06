#ifndef CUB3D_H
# define CUB3D_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# include "parsing.h"
# include "error_exit.h"

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
}	t_scene;

#endif