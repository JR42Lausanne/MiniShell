/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:19:40 by graux             #+#    #+#             */
/*   Updated: 2022/10/10 13:53:18 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_num_trimed_up(char const *s, char const *set)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] && ft_strchr(set, s[i]) != NULL)
	{
		count++;
		i++;
	}
	return (count);
}

static int	ft_num_trimed_down(char const *s, char const *set)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(s) - 1;
	while (len >= 0 && ft_strchr(set, s[len]) != NULL)
	{
		count++;
		len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimed;
	unsigned int	before;
	unsigned int	after;
	unsigned int	i;

	before = ft_num_trimed_up(s1, set);
	after = ft_num_trimed_down(s1, set);
	if (ft_strlen(s1) == before && ft_strlen(s1) == after)
		after = 0;
	trimed = malloc((ft_strlen(s1) - before - after + 1) * sizeof(char));
	if (trimed == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(s1) == before)
	{
		trimed[i] = '\0';
		return (trimed);
	}
	while (i < ft_strlen(s1) - before - after)
	{
		trimed[i] = s1[before + i];
		i++;
	}
	trimed[i] = '\0';
	return (trimed);
}
