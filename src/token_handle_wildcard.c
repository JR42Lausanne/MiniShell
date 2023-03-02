/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_wildcard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:32:11 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 10:33:15 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_handle_wildcard(t_tokenizer *toker, t_token *tok)
{
	tok->type = TOK_WILDCARD;
	token_gen_content(tok, "*", 1);
	toker->pos += 1;
}
