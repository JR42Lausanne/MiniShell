/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_check_syntax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:14:53 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 11:56:28 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"

static int	check_pipes(t_token **tokens)
{
	(void) tokens;
	return (1);
}

static int	check_redir_name(char *name)
{
	if (!name)
		return (0);
	if (name[0] == '>' || name[0] == '<')
		return (0);
	return (1);
}

static int	check_redirs(t_token **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (is_redir(tokens[i]) && !check_redir_name(tokens[i]->content)) //TODO maybe check for valie file name instead of null
		{
			error_put("syntax error", "invalid redirection filename");
			return (0);
		}
	}
	return (1);
}

int	tokens_check_syntax(t_token **tokens)
{
	if (tokens && !tokens[0])
		return (1);
	else if (!check_redirs(tokens))
		return (3);
	else if (!check_pipes(tokens))
		return (3);
	return (0);
}
