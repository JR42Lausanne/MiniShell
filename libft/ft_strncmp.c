/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:17:54 by graux             #+#    #+#             */
/*   Updated: 2022/10/10 12:28:13 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0 || (ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (s1[i] != s2[i] && i < n)
		return ((unsigned char)s1[i] - (unsigned char) s2[i]);
	else if (s1[i - 1] != s2[i - 1])
		return ((unsigned char)s1[i - 1] - (unsigned char) s2[i - 1]);
	return (0);
}
