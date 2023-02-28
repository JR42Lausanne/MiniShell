/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:06:21 by graux             #+#    #+#             */
/*   Updated: 2022/10/07 16:06:42 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cpy;

	s_cpy = (char *) s;
	while (n--)
	{
		if (*s_cpy++ == (char) c)
			return (--s_cpy);
	}
	return (NULL);
}
