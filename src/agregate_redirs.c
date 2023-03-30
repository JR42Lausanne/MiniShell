/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregate_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:28:35 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 12:43:40 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static void	replace_rest(t_token **tokens, int pos)
{
	if (tokens[pos])
		token_destroy(tokens[pos]);
	while (tokens[pos] && tokens[pos + 1])
	{
		tokens[pos] = tokens[pos + 1];
		pos++;
	}
	tokens[pos] = NULL;
}

int	is_redir(t_token *tok)
{
	if (tok->type == TOK_REDIR_IN)
		return (1);
	else if (tok->type == TOK_REDIR_OUT)
		return (1);
	else if (tok->type == TOK_REDIR_APP)
		return (1);
	else if (tok->type == TOK_HEREDOC)
		return (1);
	else
		return (0);
}

void	agregate_redirs(t_token ***tokens)
{
	int	i;

	i = 0;
	while ((*tokens)[i])
	{
		if (is_redir((*tokens)[i]))
		{
			free((*tokens)[i]->content);
			if ((*tokens)[i + 1])
				(*tokens)[i]->content = ft_strdup((*tokens)[i + 1]->content);
			else
				(*tokens)[i]->content = NULL;
			replace_rest(*tokens, i + 1);
		}
		i++;
	}
}
