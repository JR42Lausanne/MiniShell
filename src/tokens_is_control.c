/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:38:22 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 14:45:51 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

int	tokens_count_control(t_token **tokens)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tokens[++i])
	{
		if (token_is_control(tokens[i]))
			count++;
	}
	return (count);
}

int	token_is_control(t_token *tok)
{
	if (!tok)
		return (0);
	return (tok->type == TOK_PIPE || tok->type == TOK_AND
		|| tok->type == TOK_OR);
}
