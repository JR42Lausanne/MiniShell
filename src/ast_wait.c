/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:11:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/09 14:24:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_wait(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == AST_ROOT)
	{
		ast_wait(node->children[0]);
		return ;
	}
	if (node->type == AST_PIPE)
	{
		//TODO close pipe in
		close(node->pipe_out[0]);
		close(node->pipe_out[1]);
		if (node->pipe_in[0] != -1 && node->pipe_in[1] != -1)
		{
			close(node->pipe_in[0]);
			close(node->pipe_in[1]);
		}
		fprintf(stderr, "waiting for: %d\n", node->children[0]->pid);
		waitpid(node->children[0]->pid, NULL, 0);
		if (node->children[1]->pid != -1)
		{
			fprintf(stderr, "waiting for: %d\n", node->children[1]->pid);
			waitpid(node->children[1]->pid, NULL, 0);
		}
	}
	ast_wait(node->children[0]);
	ast_wait(node->children[1]);
}
