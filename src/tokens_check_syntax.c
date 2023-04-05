/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_check_syntax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:14:53 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 14:56:42 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"

static int	check_words_around(t_token **tokens, int pos)
{
	int	i;
	int	valid_right;
	int	valid_left;

	i = pos;
	valid_right = 0;
	valid_left = 0;
	while (tokens[++i])
	{
		if (tokens[i]->type == TOK_WORD || is_redir(tokens[i]))
			valid_right = 1;
		else if (tokens[i]->type == TOK_PIPE || tokens[i]->type == TOK_OR
			|| tokens[i]->type == TOK_AND)
			break ;
	}
	i = pos;
	while (--i >= 0)
	{
		if (tokens[i]->type == TOK_WORD || is_redir(tokens[i]))
			valid_left = 1;
		else if (tokens[i]->type == TOK_PIPE || tokens[i]->type == TOK_OR
			|| tokens[i]->type == TOK_AND)
			break ;
	}
	return (valid_left && valid_right);
}

static int	check_control(t_token **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (tokens[i]->type == TOK_PIPE && !check_words_around(tokens, i))
		{
			error_put("syntax error", "invalid |");
			return (0);
		}
		else if (tokens[i]->type == TOK_OR)
		{
			error_put("syntax error", "invalid ||");
			return (0);
		}
		else if (tokens[i]->type == TOK_AND)
		{
			error_put("syntax error", "invalid &&");
			return (0);
		}
	}
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
		if (is_redir(tokens[i]) && !check_redir_name(tokens[i]->content))
		{
			error_put("syntax error", "invalid redirection filename");
			return (0);
		}
	}
	return (1);
}

int	tokens_check_syntax(t_token **tokens)
{
	int	i;

	if (tokens && !tokens[0])
		return (1);
	else if (!check_redirs(tokens))
		return (3);
	else if (!check_control(tokens))
		return (3);
	else if (!check_brackets_num(tokens) || !check_brackets_o(tokens)
		|| !check_brackets_c(tokens))
		return (3);
	i = -1;
	while (tokens[++i])
	{
		if (tokens[i]->type == TOK_INVALID)
		{
			error_put("syntax error", "unterminated quote");
			return (3);
		}
	}
	return (0);
}
