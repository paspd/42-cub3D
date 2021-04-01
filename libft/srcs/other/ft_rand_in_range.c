/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_in_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:54:06 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 09:54:43 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_rand_in_range(int lower, int upper)
{
	int	num;

	num = (rand() % (upper - lower + 1)) + lower;
	return (num);
}
