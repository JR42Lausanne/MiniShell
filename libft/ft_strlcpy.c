/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:02:09 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/17 19:16:20 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{	
	size_t	i;

	if (dstsize < 1)
		return (ft_strlen(src));
	i = 0;
	while ((src[i] != '\0') && (i < dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dest1[] = "Hello def";
	char	src1[] = "Hello bonjour";
	char	dest2[] = "Hello def";
	char	src2[] = "Hello bonjour";

	printf("la valeur de dest1 est de %lu\n",strlcpy(dest1, src1, 4));
	printf("la valeur de dest2 est de %lu\n",ft_strlcpy(dest2, src2, 4));
	printf("%s\n", dest1);
	printf("%s\n", dest2);

	return (0);	
}
*/
