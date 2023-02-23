/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:49:32 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/17 18:40:18 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

static int	verif_set(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{	
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = (int)ft_strlen(s1);
	k = 0;
	while (s1[i] != '\0' && verif_set(s1[i], set))
		i++;
	while (j > i && verif_set(s1[j - 1], set))
		j--;
	new = (char *)malloc(sizeof(char) * (j - i + 1));
	if (new == 0)
		return (0);
	while (i < j)
	{
		new[k] = s1[i];
		i++;
		k++;
	}
	new[k] = '\0';
	return (new);
}
/*
int main(void)
{
	char s[] = "Bonjour ca va ?";
	char set[] = "Bo";
	printf("la nouvelle chaine de caractere est %s\n", ft_strtrim(s, set));
	return (0);
}*/
