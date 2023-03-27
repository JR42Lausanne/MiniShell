/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_tilde.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:22:48 by graux             #+#    #+#             */
/*   Updated: 2023/03/24 16:12:09 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"

void	token_handle_tilde(t_tokenizer *toker, t_token *tok)
{
	char	*value;

	if (toker->input[toker->pos + 1] == ' '
		|| toker->input[toker->pos + 1] == '\t'
		|| toker->input[toker->pos + 1] == '/'
		|| toker->input[toker->pos + 1] == '\0')
	{
		tok->type = TOK_WORD;
		toker->pos++;
		value = ms_getenv_cont("HOME");
		token_gen_content(tok, value, ft_strlen(value));
	       	//TODO maybe something if HOME is unset
		free(value);
	}
	else
		token_handle_word(toker, tok);
}
