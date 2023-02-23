/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:48:45 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/17 19:03:37 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (src > dst)
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dst)[n - 1 - i] = ((char *)src)[n - 1 - i];
			i++;
		}
	}
	return (dst);
}
/*
int main(void)
{
	char s1[] = "helli";
	char s2[] = "bonjour";
	printf("%s\n",ft_memmove(s1, s2, 4));
	return (0);
}
*/
