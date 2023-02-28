/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:10:57 by graux             #+#    #+#             */
/*   Updated: 2022/10/17 13:26:57 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_free_all(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}

static int	ft_csplits(char *str, char charset, int *count)
{
	int	trigger;
	int	i;

	trigger = 0;
	i = 0;
	*count = 0;
	while (str[i] != '\0')
	{
		if (charset != str[i] && trigger == 0)
		{
			trigger = 1;
			*count = *count + 1;
		}
		else if (charset == str[i])
			trigger = 0;
		i++;
	}
	return (*count);
}

static char	*ft_strndup(char *str, int start, int end)
{
	char	*copy;
	int		i;

	copy = malloc((end - start + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		copy[i] = str[start];
		i++;
		start++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**ft_split_plus(char **splits, char *str, char *charset)
{
	unsigned int	i;
	int				j;
	int				start;

	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(str))
	{
		if (!(*charset == str[i]) && start < 0)
			start = i;
		if (start >= 0 && ((*charset == str[i]) || (i == ft_strlen(str)
					&& !(*charset == str[i - 1]))) && ft_strlen(str) != 0)
		{
			splits[j++] = ft_strndup(str, start, i);
			if (splits[j - 1] == NULL)
				return (ft_free_all(splits, j - 1));
			start = -1;
		}
	}
	splits[j] = NULL;
	return (splits);
}

char	**ft_split(char const *s, char c)
{
	int		sc;
	char	*s_cpy;
	char	**split;

	s_cpy = (char *) s;
	if (ft_strlen(s_cpy) == 0)
	{
		split = malloc(1 * sizeof(char *));
		if (split == NULL)
			return (NULL);
		split[0] = 0;
		return (split);
	}
	split = malloc((ft_csplits((char *) s, c, &sc) + 1) * sizeof(char **));
	if (split == NULL)
		return (NULL);
	split = ft_split_plus(split, s_cpy, &c);
	if (split == NULL)
		return (NULL);
	return (split);
}
