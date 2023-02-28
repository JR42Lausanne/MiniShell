/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:19:14 by graux             #+#    #+#             */
/*   Updated: 2022/10/07 16:19:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*s_cpy;

	s_len = ft_strlen(s);
	s_cpy = (char *) s + s_len;
	while (s_len--)
	{
		if (*s_cpy == (char) c)
			return (s_cpy);
		s_cpy--;
	}
	if (*s_cpy == (char) c)
		return (s_cpy);
	return (NULL);
}
