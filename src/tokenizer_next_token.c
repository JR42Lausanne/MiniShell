/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:00:32 by graux             #+#    #+#             */
/*   Updated: 2023/03/01 17:24:24 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static void	normal_mode(t_tokenizer *toker, t_token *tok)
{
}

static void	sq_mode(t_tokenizer *toker, t_token *tok)
{
}

static void	dq_mode(t_tokenizer *toker, t_token *tok)
{
}

t_token	*tokenizer_next_token(t_tokenizer *toker)
{
	t_token		*tok;
	t_list		*new_elem;
	static int	tok_num;

	if (toker->pos == 0)
		tok_num = 0;
	if (!toker->input[toker->pos])
		return (NULL);
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	while (toker->input[toker->pos] == ' ' || toker->input[toker->pos] == '\t')
		toker->pos += 1;
	if (toker->input[toker->pos] == '\'')
		sq_mode(toker, tok);
	if (toker->input[toker->pos] == '"')
		dq_mode(toker, tok);
	else
		normal_mode(toker, tok);
	tok->tok_num = tok_num;
	new_elem = ft_lstnew(tok);
	ft_lstadd_back(&toker->tokens, new_elem);
	tok_num++;
	return (tok);
}
