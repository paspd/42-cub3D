#ifndef MAP_FOR_CUB_H
# define MAP_FOR_CUB_H

#include "../libft/incs/libft.h"

typedef	struct 	s_mfc
{
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		nb_sprite;
	char	**map;
}				t_mfc;

#endif