/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/09 14:20:33 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include <stdlib.h>
#include <stdio.h>

static void	handle_pipe(t_ast_node *node)
{
	//TODO donner tout le pipe aux childs pour close
	if (node->pipe_out[0] == -1 && node->pipe_out[0])
		pipe(node->pipe_out);
	if (node->children[1]->type == AST_PIPE)
	{
		node->children[1]->pipe_in[0] = node->pipe_out[0];
		node->children[1]->pipe_in[1] = node->pipe_out[1];
	}
	if (node->pipe_in[0] == -1 && node->pipe_in[1] == -1)
	{
		node->children[0]->pipe_redir_out.fd_old = 1;
		node->children[0]->pipe_redir_out.fd_new = node->pipe_out[1];
		node->children[0]->pipe_redir_out.fd_pipe_other = node->pipe_out[0];
		node->children[1]->pipe_redir_in.fd_old = 0;
		node->children[1]->pipe_redir_in.fd_new = node->pipe_out[0];
		node->children[1]->pipe_redir_in.fd_pipe_other = node->pipe_out[1];
	}
	else
	{
		node->children[0]->pipe_redir_in.fd_old = 0;
		node->children[0]->pipe_redir_in.fd_new = node->pipe_in[0];
		node->children[0]->pipe_redir_in.fd_pipe_other = node->pipe_in[1];
		node->children[0]->pipe_redir_out.fd_old = 1;
		node->children[0]->pipe_redir_out.fd_new = node->pipe_out[1];
		node->children[0]->pipe_redir_out.fd_pipe_other = node->pipe_out[0];
		node->children[1]->pipe_redir_in.fd_old = 0;
		node->children[1]->pipe_redir_in.fd_new = node->pipe_out[0];
		node->children[1]->pipe_redir_in.fd_pipe_other = node->pipe_out[1];
	}
}

void	ast_execute(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == AST_ROOT)
	{
		ast_execute(node->children[0]);
		return ;
	}
	//TODO specifics before calling childrens
	if (node->type == AST_PIPE)
		handle_pipe(node);
	ast_execute(node->children[0]);
	ast_execute(node->children[1]);
	if (node->type == AST_CMD)
		ast_execute_cmd(node);
	else if (node->type == AST_BUILTIN)
		ast_execute_built(node);
}
