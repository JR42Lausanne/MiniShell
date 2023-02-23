/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:21:34 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/20 11:04:05 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

static size_t	ft_sizelen(const char *s, unsigned int start, size_t len)
{
	size_t	size_s;

	size_s = ft_strlen(s);
	if (start == 0 && len == 0)
		return (0);
	if (start == 1 && len == 1)
		return (0);
	if (start > size_s)
		return (0);
	if (len > size_s - start)
		return (size_s - start);
	else
		return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_s;

	i = start;
	if (!s)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * (ft_sizelen(s, start, len) + 1));
	if (!new_s)
		return (NULL);
	j = 0;
	while (j < len && ft_strlen(s) > i)
	{
		new_s[j] = s[i];
		i++;
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}
/*
int main(void)
{
	char str[] = "Bonjour ca va";
	unsigned int	st;
	size_t		len;

	st = 8;
	len = 2;
	printf("la nouvelle chaine de caractere %s\n, ft_substr(str, st, len);
	return (0);
}
*/
