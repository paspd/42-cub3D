/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:23:27 by ldauga            #+#    #+#             */
/*   Updated: 2021/02/02 10:49:46 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int		have_return(char *save)
{
	int i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_new_line(char **save, int fd)
{
	int		i;
	char	*temp;

	if (!save)
		return (0);
	i = 0;
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	if (!(temp = gnl_ft_calloc(sizeof(char), (i + 1))))
		return (0);
	i = 0;
	while (save[fd][i] && save[fd][i] != '\n')
	{
		temp[i] = save[fd][i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_new_save(char **save, int fd)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!save[fd])
		return (0);
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	if (!save[fd][i])
	{
		free(save[fd]);
		return (0);
	}
	i++;
	if (!(temp = gnl_ft_calloc(sizeof(char), (gnl_ft_strlen(save[fd]) - i + 1))))
		return (0);
	while (save[fd][i])
		temp[j++] = save[fd][i++];
	temp[j] = '\0';
	free(save[fd]);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[4096];
	char			buff[BUFFER_SIZE + 1];
	int				reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!save[fd])
		if (!(save[fd] = gnl_ft_calloc(1, 1)))
			return (-1);
	reader = 1;
	while (reader != 0 && !(have_return(save[fd])))
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[reader] = '\0';
		save[fd] = gnl_ft_strjoin(save[fd], buff);
	}
	*line = get_new_line(save, fd);
	save[fd] = get_new_save(save, fd);
	if (reader == 0)
		return (0);
	return (1);
}
