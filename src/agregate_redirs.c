/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregate_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:28:35 by graux             #+#    #+#             */
/*   Updated: 2023/03/17 15:47:54 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static void	replace_rest(t_token **tokens, int pos)
{
	if (tokens[pos])
		token_destroy(tokens[pos]);
	while (tokens[pos + 1])
	{
		tokens[pos] = tokens[pos + 1];
		pos++;
	}
	tokens[pos] = NULL;
}

static int	is_redir(t_token *tok)
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

//TODO when redir take next word and put it's content in the redir content
void	agregate_redirs(t_token ***tokens, int size)
{
	int	i;

	(void) size;
	i = 0;
	while ((*tokens)[i])
	{
		if (is_redir((*tokens)[i]))
		{
			free((*tokens)[i]->content);
			(*tokens)[i]->content = ft_strdup((*tokens)[i + 1]->content);
			replace_rest(*tokens, i + 1);
		}
		i++;
	}
}
