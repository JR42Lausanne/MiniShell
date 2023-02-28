/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:57:40 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 16:14:38 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <stdlib.h>

t_tokenizer	*tokenizer_create(char *input)
{
	t_tokenizer	*toker;

	toker = malloc(sizeof(t_tokenizer));
	if (!toker)
		return (NULL);
	toker->tokens = NULL;
	toker->input = input;
	toker->pos = 0;
	toker->mode = MODE_NORMAL;
	return (toker);
}
