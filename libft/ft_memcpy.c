/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:07:36 by graux             #+#    #+#             */
/*   Updated: 2022/10/10 13:58:47 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest_cpy;
	char			*src_cpy;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	dest_cpy = (char *) dest;
	src_cpy = (char *) src;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
