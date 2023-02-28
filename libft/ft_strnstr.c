/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:18:28 by graux             #+#    #+#             */
/*   Updated: 2022/10/10 14:06:56 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *) big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (j < little_len && big[i + j] == little[j])
		{
			j++;
		}
		if (j == little_len && i + j <= len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
