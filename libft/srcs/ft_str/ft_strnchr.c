/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:19:45 by leodauga          #+#    #+#             */
/*   Updated: 2021/02/05 22:26:55 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int ft_strnchr(char *str, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && str[i])
    {
        if (str[i] == c)
        return (1);
        i++;
    }
    return (0);
}