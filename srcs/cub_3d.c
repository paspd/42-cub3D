/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:00:33 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/05 11:12:54 by ldauga           ###   ########lyon.fr   */
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

int	parsing(t_cub *cub)
{
	parsing_file(cub);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub	cub;

	init_structs((char *)argv[1], &cub);
	if (argc == 2 || (argc == 3 && !ft_strcmp(argv[2], "--save")))
		parsing(&cub);
	else if (argc < 2)
		error("U must put a map's file path.\n", &cub);
	else if (argc > 2)
		error("U must one map's file path (or --save).\n", &cub);
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		cub.verif.save = 1;
	cub.mlx.id = mlx_init();
	if (!cub.mlx.id)
		error("MLX error.\n", &cub);
	cub.wind.id = mlx_new_window(cub.mlx.id, cub.wind.width, \
		cub.wind.height, "Cub3D");
	if (!cub.wind.id)
		error("MLX error.\n", &cub);
	aff_all(&cub);
	start_graphic(&cub);
	mlx_loop(cub.mlx.id);
	return (0);
}
