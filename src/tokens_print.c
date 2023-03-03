/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:18:05 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 16:17:13 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <stdio.h>

static const char	*g_tokens_str[] = {
[TOK_WORD] = "TOK_WORD",
[TOK_SQ] = "TOK_SQ",
[TOK_DQ] = "TOK_DQ",
[TOK_VAR] = "TOK_VAR",
[TOK_PIPE] = "TOK_PIPE",
[TOK_OR] = "TOK_OR",
[TOK_AND] = "TOK_AND",
[TOK_WILDCARD] = "TOK_WILDCARD",
[TOK_REDIR_IN] = "TOK_REDIR_IN",
[TOK_REDIR_OUT] = "TOK_REDIR_OUT",
[TOK_REDIR_APP] = "TOK_REDIR_APP",
[TOK_HEREDOC] = "TOK_HEREDOC",
[TOK_INVALID] = "TOK_INVALID"
};

static void	print_tok(t_token *tok)
{
	printf("%d: %-15s -> %s\n", tok->tok_num, g_tokens_str[tok->type],
		tok->content);
}

void	tokens_print(t_token **tokens)
{
	int	i;

	if (!tokens)
	{
		printf("This token array is empty\n");
		return ;
	}
	i = -1;
	while (tokens[++i])
		print_tok(tokens[i]);
}
