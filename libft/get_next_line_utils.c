/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:36:39 by jlaiti            #+#    #+#             */
/*   Updated: 2022/11/30 10:26:18 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft1_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft1_strchr(char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	i = -1;
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (new == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
