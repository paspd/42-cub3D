/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:19:52 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/02 10:13:52 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	n = 0;
	while (s1[i])
	{
		str[n] = s1[i];
		i++;
		n++;
	}
	i = 0;
	while (s2[i])
		str[n++] = s2[i++];
	str[n] = 0;
	free(s1);
	return (str);
}
