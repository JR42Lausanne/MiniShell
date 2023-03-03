/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:21:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 17:24:49 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

t_token	**tokenize_input(char *input)
{
	t_tokenizer	*toker;
	t_token		**tokens;

	toker = tokenizer_create(input);
	tokens = tokenizer_parse(toker);
	tokenizer_destroy(toker);
	return (tokens);
}
