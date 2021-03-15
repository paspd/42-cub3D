/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:48 by leodauga          #+#    #+#             */
/*   Updated: 2021/02/05 20:56:28 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void    ft_putchar_color(int c, char *color)
{
    ft_putstr(color);
    ft_putchar(c);
    ft_putstr("\033[0m");
}