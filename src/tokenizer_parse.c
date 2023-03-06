/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:01:38 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 09:49:02 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

t_token	**tokenizer_parse(t_tokenizer *toker)
{
	t_token	*token;

	token = tokenizer_next_token(toker);
	while (token)
		token = tokenizer_next_token(toker);
	return (tokenizer_as_array(toker));
}
