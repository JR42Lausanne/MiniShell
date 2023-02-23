/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:25:13 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/17 19:20:29 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_lenght;
	size_t	src_lenght;
	size_t	i;

	dst_lenght = ft_strlen(dst);
	src_lenght = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - dst_lenght - 1)
		&& dstsize > dst_lenght)
	{
		dst[dst_lenght + i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[dst_lenght + i] = '\0';
	if (dstsize < dst_lenght)
		return (src_lenght + dstsize);
	else
		return (src_lenght + dst_lenght);
}	
/*
int main(void)
{
	char s1[20] = "pqrstuvwyz";
	char s2[] = "abcd";
	char s01[20] = "pqrstuvwyz";
	char s02[] = "abcd";
	printf("la fonction strlcat concatenne %lu\n", strlcat(s1, s2, 7));
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%zu\n", strlen(s01));
	printf("la fonction ft_strlcat %lu\n", ft_strlcat(s01, s02, 7));
	printf("%s\n", s01);
	printf("%s\n", s02);
}
*/
