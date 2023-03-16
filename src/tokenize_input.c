/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:21:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/16 15:26:42 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static void	to_words(t_token **tokens)
{
	int		i;
	int		size;

	size = tokens_size(tokens);
	i = -1;
	while (++i < size)
	{
		if (tokens[i]->type == TOK_SQ || tokens[i]->type == TOK_DQ
			|| tokens[i]->type == TOK_VAR)
			tokens[i]->type = TOK_WORD;
	}
}

t_token	**tokenize_input(char *input)
{
	t_tokenizer	*toker;
	t_token		**tokens;
	int			size;

	toker = tokenizer_create(input);
	tokens = tokenizer_parse(toker);
	to_words(tokens);
	size = tokens_size(tokens);
	tokens = agregate_spaces(tokens, size);
	agregate_redirs(tokens, size);
	tokenizer_destroy(toker);
	return (tokens);
}
