/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:29:32 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/18 14:47:43 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && in_word)
		{	
			in_word = 0;
			count++;
		}
		if (s[i] != c)
			in_word = 1;
		i++;
	}	
	if (s[i - 1] == c)
		count--;
	return (count + 1);
}

static int	ft_sizewords(char const *s, char c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	return (i);
}

static void	*ft_free(char **split, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
		free(split[i++]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{	
	char	**split;
	int		pos;
	int		i;

	i = -1;
	if (ft_strlen(s) == 0)
		return (ft_calloc(1, sizeof(char **)));
	split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (split == NULL)
		return (NULL);
	pos = 0;
	while (++i < ft_count_words(s, c))
	{	
		while (s[pos] == c)
			pos++;
		split[i] = (char *)malloc(sizeof(char)
				* (ft_sizewords(&s[pos], c) + 1));
		if (split[i] == NULL)
			return (ft_free(split, i));
		ft_strlcpy(split[i], &s[pos], ft_sizewords(&s[pos], c) + 1);
		pos += ft_sizewords(&s[pos], c);
	}
	split[i] = NULL;
	return (split);
}

/*
int	main(int argc, char *argv[])
{
	int		i;
	char	**split;

	i = 0;
	if (argc < 1)
		return (0);
	split = ft_split(argv[1], *argv[2]);
	while (split[i])
	{
		printf("%d: %s\n", i, split[i]);
		i++;
	}
	return (0);
}
*/
