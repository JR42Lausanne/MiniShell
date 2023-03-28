/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:23:53 by graux             #+#    #+#             */
/*   Updated: 2023/03/28 17:33:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	tokens_destroy(t_token **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = -1;
	while (tokens[++i])
		token_destroy(tokens[i]);
	free(tokens);
}

void	token_destroy(t_token *tok)
{
	if (!tok)
		return ;
	free(tok->content);
	free(tok);
}
