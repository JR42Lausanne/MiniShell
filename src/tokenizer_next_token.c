/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:00:32 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 13:44:42 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"
#include "../include/libft.h"

static void	normal_mode(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos] == '('
		|| toker->input[toker->pos] == ')')
		token_handle_brackets(toker, tok);
	else if (toker->input[toker->pos] == '|')
		token_handle_pipe(toker, tok);
	else if (toker->input[toker->pos] == '&')
		token_handle_and(toker, tok);
	else if (toker->input[toker->pos] == '<')
		token_handle_redir_i(toker, tok);
	else if (toker->input[toker->pos] == '>')
		token_handle_redir_o(toker, tok);
	else if (toker->input[toker->pos] == '$')
		token_handle_var(toker, tok);
	else if (toker->input[toker->pos] == '~')
		token_handle_tilde(toker, tok);
	else
		token_handle_word(toker, tok);
}

static void	sq_mode(t_tokenizer *toker, t_token *tok)
{
	char	*closing_sq;
	long	str_size;

	tok->type = TOK_SQ;
	toker->pos += 1;
	closing_sq = ft_strchr(toker->input + toker->pos, '\'');
	if (!closing_sq)
	{
		token_gen_content(tok, "Invalid sq string", 17);
		tok->type = TOK_INVALID;
		return ;
	}
	str_size = closing_sq - (toker->input + toker->pos);
	token_gen_content(tok, toker->input + toker->pos, str_size);
	toker->pos += str_size + 1;
}

t_token	*tokenizer_next_token(t_tokenizer *toker)
{
	t_token		*tok;
	t_list		*new_elem;

	if (!toker->input[toker->pos])
		return (NULL);
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->to_be_removed = 0;
	if (toker->input[toker->pos] == ' ' || toker->input[toker->pos] == '\t')
		token_handle_space(toker, tok);
	else if (toker->input[toker->pos] == '\'')
		sq_mode(toker, tok);
	else if (toker->input[toker->pos] == '"')
		dq_mode(toker, tok);
	else
		normal_mode(toker, tok);
	new_elem = ft_lstnew(tok);
	if (!new_elem)
		return (NULL);
	ft_lstadd_back(&toker->tokens, new_elem);
	return (tok);
}
