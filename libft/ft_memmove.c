/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:08:14 by graux             #+#    #+#             */
/*   Updated: 2022/10/11 13:22:38 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_cpy;
	char	*src_cpy;

	if (dest == NULL && src == NULL)
		return (dest);
	dest_cpy = (char *) dest;
	src_cpy = (char *) src;
	if (dest_cpy < src_cpy + n && src_cpy < dest_cpy)
	{
		dest_cpy += n;
		src_cpy += n;
		while (n--)
			*--dest_cpy = *--src_cpy;
	}
	else
		while (n--)
			*dest_cpy++ = *src_cpy++;
	return (dest);
}
