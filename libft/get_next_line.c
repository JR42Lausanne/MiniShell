/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:48:29 by graux             #+#    #+#             */
/*   Updated: 2022/10/31 11:50:46 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_grow_buffer(char *next, char *buffer)
{
	char	*bigger;
	int		i;
	int		j;

	if (!next)
	{
		next = malloc(sizeof(char));
		if (!next)
			return (NULL);
		next[0] = '\0';
	}
	bigger = malloc((ft_strlen(next) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!bigger)
		return (NULL);
	i = -1;
	while (next[++i])
		bigger[i] = next[i];
	j = 0;
	while (buffer[j])
		bigger[i++] = buffer[j++];
	bigger[i] = '\0';
	free(next);
	return (bigger);
}

static char	*ft_read_toendln(int fd, char *next)
{
	char	buffer[BUFFER_SIZE + 1];
	int		size_read;

	size_read = 1;
	while (!ft_isendln(next) && size_read != 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			if (next)
				free(next);
			return (NULL);
		}
		buffer[size_read] = '\0';
		next = ft_grow_buffer(next, buffer);
		if (!next)
			return (NULL);
	}
	return (next);
}

static char	*ft_get_line(char *next)
{
	char	*line;
	int		i;

	i = 0;
	if (!next[i])
		return (NULL);
	while (next[i] && next[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (next[i] && next[i] != '\n')
	{
		line[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_ready_for_next(char *next)
{
	char	*ready;
	int		i;
	int		j;

	if (!next)
		return (NULL);
	i = 0;
	while (next[i] && next[i] != '\n')
		i++;
	if (next[i] == '\0')
	{
		free(next);
		return (NULL);
	}
	ready = malloc((ft_strlen(next) - i++ + 1) * sizeof(char));
	if (!ready)
		return (NULL);
	j = 0;
	while (next[i])
	{
		ready[j++] = next[i++];
	}
	ready[j] = '\0';
	free(next);
	return (ready);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next[257];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	next[fd] = ft_read_toendln(fd, next[fd]);
	if (!next[fd])
		return (NULL);
	line = ft_get_line(next[fd]);
	next[fd] = ft_ready_for_next(next[fd]);
	return (line);
}
