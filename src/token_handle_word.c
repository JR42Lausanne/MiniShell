/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:00:50 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 16:17:11 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static const char	*g_special_chars = "|$\'\"<>&* \t";

static int	in_tok_word(char c)
{
	int	i;

	i = -1;
	while (g_special_chars[++i])
	{
		if (g_special_chars[i] == c)
			return (0);
	}
	return (1);
}

static int	word_size(t_tokenizer *toker)
{
	int	size;

	size = -1;
	while (toker->input[toker->pos + ++size])
	{
		if (!in_tok_word(toker->input[toker->pos + size]))
			break ;
	}
	return (size);
}

void	token_handle_word(t_tokenizer *toker, t_token *tok)
{
	int	size;

	tok->type = TOK_WORD;
	size = word_size(toker);
	token_gen_content(tok, toker->input + toker->pos, size);
	toker->pos += size;
}
