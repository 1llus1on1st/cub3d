#include "cub3d.h"

void	validate_map(t_scene *scene)
{
	validate_map_chars(scene);
	validate_player(scene);
	validate_closed(scene);
}
