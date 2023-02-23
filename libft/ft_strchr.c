/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:47:43 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/12 16:53:44 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *) s;
	while (*s_copy != '\0')
	{
		if (*s_copy == (char) c)
			return (s_copy);
		s_copy++;
	}
	if (*s_copy == (char) c)
		return (s_copy);
	return (NULL);
}
