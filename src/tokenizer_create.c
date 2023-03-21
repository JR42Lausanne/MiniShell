/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:57:40 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 13:38:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/libft.h"
#include <stdlib.h>

t_tokenizer	*tokenizer_create(char *input, int status)
{
	t_tokenizer	*toker;

	toker = malloc(sizeof(t_tokenizer));
	if (!toker)
		return (NULL);
	toker->tokens = NULL;
	toker->input = ft_strdup(input);
	toker->status = status;
	toker->pos = 0;
	return (toker);
}
