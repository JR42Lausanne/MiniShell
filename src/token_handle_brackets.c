/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_brackets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:20:20 by graux             #+#    #+#             */
/*   Updated: 2023/03/28 13:30:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_brackets(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos] == '(')
	{
		tok->type = TOK_BRACK_O;
		token_gen_content(tok, "(", 1);
	}
	else
	{
		tok->type = TOK_BRACK_C;
		token_gen_content(tok, ")", 1);
	}
	toker->pos += 1;
}
