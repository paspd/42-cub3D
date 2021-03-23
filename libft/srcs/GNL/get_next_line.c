/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:03:38 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/23 10:25:07 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	save_check(char *buffer)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (buffer[i])
			return (i);
		i++;
	}
	return (-1);
}

int	process(char **line, char *buffer, int save, int fd)
{
	int	len;
	int	eol;

	eol = 0;
	while (1)
	{
		save = save_check(buffer);
		len = gnl_ft_strlen(buffer, save);
		if (buffer[save + len] == '\n')
			eol = 1;
		if ((*line)[0] == 0)
			gnl_ft_strcpy(*line, buffer, len, save);
		else
			*line = gnl_ft_strjoin(*line, buffer, len, save);
		if (*line == NULL)
			return (-1);
		if (eol)
			return (1);
		if (read(fd, buffer, 1) == 0)
			return (0);
	}
	return (-1);
}

int	nosave_noread(char **line)
{
	*line = malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	*line[0] = 0;
	return (0);
}

int	mini_calloc(char **line, int len)
{
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return (0);
	(*line)[0] = '\0';
	(*line)[len] = 0;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			len;
	int			save;
	int			z;
	static char	buffer[OPEN_MAX][1 + 1] = {{0}};

	len = 0;
	z = 0;
	*line = NULL;
	if (fd < 0 || fd >= OPEN_MAX)
		return (-1);
	save = save_check(buffer[fd]);
	if (save == -1)
		z = read(fd, buffer[fd], 1);
	if (save == -1 && z == 0)
		return (nosave_noread(line));
	save = save_check(buffer[fd]);
	if (z > 0 || save >= 0)
	{
		len = gnl_ft_strlen(buffer[fd], save);
		if (!(mini_calloc(line, len)))
			return (-1);
		z = process(line, buffer[fd], save, fd);
	}
	return (z);
}
