/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:53:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 17:55:14 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

int	tokens_size(t_token **tokens)
{
	int	size;

	if (!tokens)
		return (0);
	size = 0;
	while (tokens[size])
		size++;
	return (size);
}
