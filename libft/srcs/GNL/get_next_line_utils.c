/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:54:53 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/02 10:50:41 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

size_t		gnl_ft_strlen(const char *c)
{
	int	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i])
		i++;
	return (i);
}

char		*gnl_ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*str;

	if (!s2 || !s1)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_calloc(sizeof(char), i + 1)))
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

void		gnl_ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	str = s;
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		n--;
		i++;
	}
}

void		*gnl_ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (count * size))))
		return (0);
	ft_bzero(str, (count * size));
	return (str);
}
