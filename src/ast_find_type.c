/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_find_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:38:21 by graux             #+#    #+#             */
/*   Updated: 2023/03/04 11:54:46 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static const t_ast_node_type	g_toktype_to_asttype[] = {
[TOK_PIPE] = AST_PIPE,
[TOK_AND] = AST_COND_AND,
[TOK_OR] = AST_COND_OR,
};

static int	ast_find_tok(t_token_type type, t_token **tokens, int start,
		int size)
{
	int	pos;

	pos = 0;
	while (pos < size)
	{
		if (tokens[pos + start]->type == type)
			return (pos + start);
		pos++;
	}
	return (-1);
}

int	ast_find_type(t_ast_node *node, t_token **tokens, int start,
		int size)
{
	int							i;
	int							tok_pos;
	static const t_token_type	checked_types[] = {
		TOK_PIPE, TOK_AND, TOK_OR
	};

	i = -1;
	while (++i < 3)
	{
		tok_pos = ast_find_tok(checked_types[i], tokens, start, size);
		if (tok_pos != -1)
		{
			node->type = g_toktype_to_asttype[checked_types[i]];
			return (tok_pos);
		}
	}
	return (-1);
}
