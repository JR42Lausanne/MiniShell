/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:56:09 by graux             #+#    #+#             */
/*   Updated: 2023/03/29 10:00:07 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

static void	free_content(t_ast_node *node)
{
	if (node->type == AST_CMD)
	{
		free(((t_cmd_cont *) node->content)->cmd_name);
		free_args(((t_cmd_cont *) node->content)->args);
	}
	else
		free_args(((t_builtin_cont *) node->content)->args);
	free(node->content);
}

void	ast_node_destroy(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == AST_CMD || node->type == AST_BUILTIN)
		free_content(node);
	if (node->type == AST_ROOT)
	{
		free(node->all_pipes);
		free(node->pipe_index);
		free(node->all_redirs);
		free(node->redir_index);
	}
	ast_node_destroy(node->children[0]);
	ast_node_destroy(node->children[1]);
	free(node);
}
