/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matches_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:20 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/29 16:41:39 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <dirent.h>

int	matches_len(char **matches)
{
	int	len;

	len = 0;
	if (!matches)
		return (0);
	while (matches[len])
		len++;
	return (len);
}
