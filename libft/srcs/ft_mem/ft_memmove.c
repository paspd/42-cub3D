/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:34:54 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/01 13:14:08 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	if (dest == src)
		return (dest);
	if (dest > src)
		while (len)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	else
		ft_memcpy(dest, src, len);
	return ((unsigned char *)dest);
}
