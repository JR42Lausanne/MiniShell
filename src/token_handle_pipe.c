/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:54:39 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 10:25:38 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_pipe(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos + 1] == '|')
	{
		tok->type = TOK_OR;
		token_gen_content(tok, "||", 2);
		toker->pos += 2;
	}
	else
	{
		tok->type = TOK_PIPE;
		token_gen_content(tok, "|", 1);
		toker->pos += 1;
	}
}
