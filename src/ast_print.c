/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:06:09 by graux             #+#    #+#             */
/*   Updated: 2023/03/04 15:43:32 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static const char	*g_ast_string[] = {
[AST_ROOT] = "AST_ROOT",
[AST_BUILTIN] = "AST_BUILTIN",
[AST_CMD] = "AST_CMD",
[AST_COND_AND] = "AST_COND_AND",
[AST_COND_OR] = "AST_COND_OR",
[AST_IN_REDIR] = "AST_IN_REDIR",
[AST_HEREDOC] = "AST_HEREDOC",
[AST_OUT_REDIR] = "AST_OUT_REDIR",
[AST_OUT_APPEND] = "AST_OUT_APPEND",
[AST_PIPE] = "AST_PIPE",
[AST_TYPE_SIZE] = "AST_TYPE_SIZE"
};

void	ast_print(t_ast_node *node, int depth)
{
	if (!node)
		return ;
	printf("%*c%d -> %s START\n", depth, ' ', depth, g_ast_string[node->type]);
	ast_print(node->children[0], depth + 1);
	ast_print(node->children[1], depth + 1);
	printf("%*c%d -> %s END\n", depth, ' ', depth,
		g_ast_string[node->type]);
}
