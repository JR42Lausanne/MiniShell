/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:21:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 13:40:19 by graux            ###   ########.fr       */
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

static void	remove_useless(t_token **tokens)
{
	int	i;
	int	j;

	i = -1;
	while (tokens[++i])
	{
		while (tokens[i] && tokens[i]->to_be_removed)
		{
			j = 0;
			token_destroy(tokens[i]);
			while (tokens[i + j])
			{
				tokens[i + j] = tokens[i + j + 1];
				j++;
			}
		}
	}
}

t_token	**tokenize_input(char *input, int status)
{
	t_tokenizer	*toker;
	t_token		**tokens;
	int			size;

	toker = tokenizer_create(input, status);
	tokens = tokenizer_parse(toker);
	to_words(tokens);
	size = tokens_size(tokens);
	tokens = agregate_spaces(tokens, size);
	remove_useless(tokens);
	size = tokens_size(tokens);
	agregate_redirs(&tokens, size);
	tokens = expand_wildcards(tokens);
	tokenizer_destroy(toker);
	return (tokens);
}
