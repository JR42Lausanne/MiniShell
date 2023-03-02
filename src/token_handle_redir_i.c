/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_redir_i.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:39:16 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 10:40:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_redir_i(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos + 1] == '<')
	{
		tok->type = TOK_HEREDOC;
		token_gen_content(tok, "<<", 2);
		toker->pos += 2;
	}
	else
	{
		tok->type = TOK_REDIR_IN;
		token_gen_content(tok, "<", 1);
		toker->pos += 1;
	}
}
