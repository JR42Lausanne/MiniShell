/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:41:41 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/17 19:18:27 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)(s + size));
	while ((size - 1 - i) >= 0)
	{
		if (s[size -1 - i] == (char)c)
			return ((char *)(s + size - 1 - i));
		i++;
	}
	return (0);
}	
