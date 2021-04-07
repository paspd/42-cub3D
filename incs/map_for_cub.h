#ifndef MAP_FOR_CUB_H
# define MAP_FOR_CUB_H

# include "../libft/incs/libft.h"

typedef struct s_mfc
{
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		nb_sprite;
	char	**map;
}				t_mfc;

void	mfc_error(char *error_msg);
int		check_argv(const char *s1, const char *s2);
int		malloc_map(t_mfc *mfc);
void	free_map(t_mfc *mfc);
void	put_player(t_mfc *mfc);
int		randomizer_map(int percent_nb1, int percent_nb2);
void	mfc_aff_map(t_mfc mfc);
void	new_map(t_mfc *mfc);

#endif