/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_redir_o.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:41:03 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 10:42:12 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_redir_o(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos + 1] == '>')
	{
		tok->type = TOK_REDIR_APP;
		token_gen_content(tok, ">>", 2);
		toker->pos += 2;
	}
	else
	{
		tok->type = TOK_REDIR_OUT;
		token_gen_content(tok, ">", 1);
		toker->pos += 1;
	}
}
