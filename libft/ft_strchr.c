/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:13:42 by graux             #+#    #+#             */
/*   Updated: 2022/10/07 16:13:56 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char *) s;
	while (*s_cpy)
	{
		if (*s_cpy == (char) c)
			return (s_cpy);
		s_cpy++;
	}
	if (*s_cpy == (char) c)
		return (s_cpy);
	return (NULL);
}
