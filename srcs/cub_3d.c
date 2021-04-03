/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:00:33 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/03 14:36:22 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"


void	start_graphic(t_cub	*cub)
{
	init_img(cub);
	init_vector(cub);
	raycasting(cub);
	mlx_hook(cub->wind.id, 2, 0, key_press, cub);
	mlx_hook(cub->wind.id, 3, 1, key_release, cub);
	mlx_hook(cub->wind.id, 17, 1, game_finish, cub);
	mlx_loop_hook(cub->mlx.id, raycasting, cub);
}

int	parsing(char *path, t_cub *cub)
{
	init_structs(path, cub);
	parsing_file(cub);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub cub;

	if (argc == 2 || (argc == 3 && !ft_strcmp(argv[2], "--save")))
		parsing((char *)argv[1], &cub);
	else if (argc < 2)
	{
		ft_putstr("\033[31m\033[1mERROR: \033[0m");
		ft_putstr("\033[38;5;166mVeuillez entrer en argument ");
		ft_putstr("le path d'une carte\033[0m");
		exit (-1);
	}
	else if (argc > 2)
	{
		ft_putstr("\033[31m\033[1mERROR: \033[0m");
		ft_putstr("\033[38;5;166mVeuillez entrer en argument ");
		ft_putstr("un seul path de carte\033[0m");
		exit (-1);
	}
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		cub.verif.save = 1;
	if (!(cub.mlx.id = mlx_init()))
		error("MLX error.\n", &cub);
	if (!(cub.wind.id = mlx_new_window(cub.mlx.id, cub.wind.width, cub.wind.height, "Cub3D")))
		error("MLX error.\n", &cub);
	aff_all(&cub);
	start_graphic(&cub);
	mlx_loop(cub.mlx.id);
	return (0);
}