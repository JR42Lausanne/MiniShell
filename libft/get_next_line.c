/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:35:25 by jlaiti            #+#    #+#             */
/*   Updated: 2022/11/30 10:33:04 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*search_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff[0])
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*rest_line(char	*buff)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft1_strlen(buff) - i + 1));
	if (rest == NULL)
		return (NULL);
	if (buff[i] == '\n')
		i++;
	j = 0;
	while (buff[i])
		rest[j++] = buff[i++];
	rest[j] = '\0';
	free(buff);
	return (rest);
}

static char	*read_file(int fd, char *file)
{
	int		count;
	char	reader[BUFFER_SIZE + 1];

	count = 1;
	while (!ft1_strchr(file, '\n') && count != 0)
	{
		count = read(fd, reader, BUFFER_SIZE);
		if (count == -1)
		{
			free(file);
			return (NULL);
		}
		reader[count] = '\0';
		file = ft_join(file, reader);
	}
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = search_line(buff[fd]);
	buff[fd] = rest_line(buff[fd]);
	return (line);
}
