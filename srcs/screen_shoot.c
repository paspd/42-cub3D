/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:19:39 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/06 15:43:59 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub.h"

void	create_bitmap_header(t_cub *cub, unsigned char **file, int size)
{
	(*file)[0] = (unsigned char)('B');
	(*file)[1] = (unsigned char)('M');
	(*file)[2] = (unsigned char)(size);
	(*file)[3] = (unsigned char)(size >> 8);
	(*file)[4] = (unsigned char)(size >> 16);
	(*file)[5] = (unsigned char)(size >> 24);
	(*file)[10] = (unsigned char)(54);
	(*file)[0 + 14] = (unsigned char)(40);
	(*file)[4 + 14] = (unsigned char)(cub->wind.width >> 0);
	(*file)[5 + 14] = (unsigned char)(cub->wind.width >> 8);
	(*file)[6 + 14] = (unsigned char)(cub->wind.width >> 16);
	(*file)[7 + 14] = (unsigned char)(cub->wind.width >> 24);
	(*file)[8 + 14] = (unsigned char)(cub->wind.height >> 0);
	(*file)[9 + 14] = (unsigned char)(cub->wind.height >> 8);
	(*file)[10 + 14] = (unsigned char)(cub->wind.height >> 16);
	(*file)[11 + 14] = (unsigned char)(cub->wind.height >> 24);
	(*file)[12 + 14] = (unsigned char)(1);
	(*file)[14 + 14] = (unsigned char)(cub->rci.bits_per_pixel);
}

void	copy_img(t_cub *cub, unsigned char **screen)
{
	int	rci_x;
	int	rci_y;
	int	ni_i;

	ni_i = 54;
	rci_y = cub->wind.height - 1;
	while (rci_y >= 0 )
	{
		rci_x = 0;
		while (rci_x < cub->wind.width)
		{
			(*screen)[ni_i++] = (cub->rci.addr[rci_y * \
				cub->rci.line_length + rci_x]);
			(*screen)[ni_i++] = (cub->rci.addr[rci_y * \
				cub->rci.line_length + rci_x] >> 8);
			(*screen)[ni_i++] = (cub->rci.addr[rci_y * \
				cub->rci.line_length + rci_x] >> 16);
			(*screen)[ni_i++] = (cub->rci.addr[rci_y * \
				cub->rci.line_length + rci_x] >> 24);
			rci_x++;
		}
		rci_y--;
	}
}

void	screen_shoot(t_cub *cub)
{
	unsigned char	*screen;
	int				fd;
	int				size;

	size = 54 + 4 * cub->wind.height * cub->wind.width;
	screen = ft_calloc(size, sizeof(unsigned char));
	if (!screen)
		error("MALLOC error.\n", cub);
	fd = open("screenshoot/s_1.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0700);
	create_bitmap_header(cub, &screen, size);
	copy_img(cub, &screen);
	write(fd, screen, size);
	free(screen);
	if (cub->verif.save)
		game_finish(cub);
}
