/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:48:43 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 16:59:00 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_space(t_tokenizer *toker, t_token *tok)
{
	tok->type = TOK_SPACE;
	while (toker->input[toker->pos] == ' ' || toker->input[toker->pos] == '\t')
		toker->pos += 1;
	token_gen_content(tok, " ", 1);
}
