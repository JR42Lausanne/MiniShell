/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:57:27 by graux             #+#    #+#             */
/*   Updated: 2022/10/11 13:38:40 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	total;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	total = nmemb * size;
	if ((size_t) -1 / nmemb < size)
		return (NULL);
	allocated = malloc(total);
	if (allocated == NULL)
		return (NULL);
	ft_bzero(allocated, total);
	return (allocated);
}
