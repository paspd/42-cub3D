/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:37:40 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:25:08 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_open_files(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (!fd)
		return (0);
	return (fd);
}
