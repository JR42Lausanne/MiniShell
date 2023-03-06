/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_and.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:28:09 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 10:35:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_and(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos + 1] == '&')
	{
		tok->type = TOK_AND;
		token_gen_content(tok, "&&", 2);
		toker->pos += 2;
	}
	else
	{
		tok->type = TOK_INVALID;
		token_gen_content(tok, "&", 1);
		toker->pos += 1;
	}
}
