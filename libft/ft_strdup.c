/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:24:33 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/17 18:38:32 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*chaine;

	size = 0;
	i = 0;
	while (s1[size] != '\0')
		size++;
chaine = malloc((size + 1) * sizeof(char));
	if (chaine == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		chaine[i] = s1[i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
