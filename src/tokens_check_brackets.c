/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_check_brackets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:57:27 by graux             #+#    #+#             */
/*   Updated: 2023/03/28 13:58:08 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"

int	check_brackets_num(t_token **tokens)
{
	int	i;
	int	count_o;
	int	count_c;

	i = -1;
	count_o = 0;
	count_c = 0;
	while (tokens[++i])
	{
		if (tokens[i]->type == TOK_BRACK_O)
			count_o++;
		else if (tokens[i]->type == TOK_BRACK_C)
			count_c++;
	}
	if (count_o != count_c)
	{
		error_put("syntax error", "unmatched parenthesis");
		return (0);
	}
	return (1);
}

int	check_brackets_o(t_token **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (tokens[i]->type == TOK_BRACK_O)
		{
			if (i != 0 && !token_is_control(tokens[i - 1])
				&& tokens[i - 1]->type != TOK_BRACK_O)
			{
				error_put("syntax error", "invalid parensenthesis block");
				return (0);
			}
		}
	}
	return (1);
}

int	check_brackets_c(t_token **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i + 1])
	{
		if (tokens[i]->type == TOK_BRACK_C)
		{
			if (!token_is_control(tokens[i + 1])
				&& tokens[i + 1]->type != TOK_BRACK_C)
			{
				error_put("syntax error", "invalid parensenthesis block");
				return (0);
			}
		}
	}
	return (1);
}
