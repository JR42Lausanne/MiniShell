/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 18:51:07 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include <stdlib.h>
#include <stdio.h>

void	ast_execute(t_ast_node *node)
{
	int	pipe_fd[2];

	if (!node)
		return ;
	if (node->type == AST_ROOT)
	{
		ast_execute(node->children[0]);
		return ;
	}
	//TODO specifics before calling childrens
	if (node->type == AST_PIPE)
	{
		//TODO donner tout le pipe aux childs pour close
		pipe(pipe_fd);
		node->children[0]->pipe_redir.fd_old = 1;
		node->children[0]->pipe_redir.fd_new = pipe_fd[1];
		node->children[1]->pipe_redir.fd_old = 0;
		node->children[1]->pipe_redir.fd_new = pipe_fd[0];
	}
	ast_execute(node->children[0]);
	ast_execute(node->children[1]);
	if (node->type == AST_CMD)
		ast_execute_cmd(node);
	else if (node->type == AST_BUILTIN)
		ast_execute_built(node);
}
