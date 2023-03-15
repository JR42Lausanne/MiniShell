/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/15 16:45:48 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include <stdlib.h>
#include <stdio.h>

static void	first_pipe(t_ast_node *node)
{
	fprintf(stderr, "First pipe\n");
	fprintf(stderr, "pipe_fd[0] = %d pipe_fd[1] = %d\n", node->all_pipes[*(node->pipe_index)], node->all_pipes[*(node->pipe_index) + 1]);
	node->children[0]->fd_in = STDIN_FILENO;
	node->children[0]->fd_out = node->all_pipes[*(node->pipe_index) + 1];
	//node->children[0]->fd_to_close[0] = node->all_pipes[*(node->pipe_index)];
	//node->children[0]->fd_to_close[1] = node->all_pipes[*(node->pipe_index) + 1];
	if (node->pipe_count == 1)
	{
		node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
		node->children[1]->fd_out = STDOUT_FILENO;
		//node->children[1]->fd_to_close[0] = node->all_pipes[*(node->pipe_index) + 1];
		//node->children[1]->fd_to_close[1] = node->all_pipes[*(node->pipe_index)];
	}
	else
	{
		node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
		node->children[1]->fd_out = node->all_pipes[*(node->pipe_index) + 3];
		//node->children[1]->fd_to_close[0] = node->all_pipes[*(node->pipe_index)];
		//node->children[1]->fd_to_close[1] = node->all_pipes[*(node->pipe_index) + 1];
	}
}

static void	last_pipe(t_ast_node *node)
{
	fprintf(stderr, "Last pipe\n");
	fprintf(stderr, "pipe_fd[0] = %d pipe_fd[1] = %d\n", node->all_pipes[*(node->pipe_index)], node->all_pipes[*(node->pipe_index) + 1]);
	node->children[0]->fd_in = node->fd_in;
	node->children[0]->fd_out = node->all_pipes[*(node->pipe_index) + 1];
	//node->children[0]->fd_to_close[0] = node->fd_to_close[0];
	//node->children[0]->fd_to_close[1] = node->fd_to_close[1];
	//node->children[0]->fd_to_close[2] = node->all_pipes[*(node->pipe_index)];
	//node->children[0]->fd_to_close[3] = node->all_pipes[*(node->pipe_index) + 1];
	node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
	node->children[1]->fd_out = STDOUT_FILENO;
	//node->children[1]->fd_to_close[0] = node->all_pipes[*(node->pipe_index) + 1];
	//node->children[1]->fd_to_close[1] = node->all_pipes[*(node->pipe_index)];
}

static void	default_pipe(t_ast_node *node)
{
	int	pipe_fd[2];

	fprintf(stderr, "Default pipe\n");
	(void) node;
	pipe(pipe_fd);
}

static void	handle_pipe(t_ast_node *node)
{
	if (!node)
		return ;
	if (*(node->pipe_index) == 0)
		first_pipe(node);
	else if (*(node->pipe_index) == (node->pipe_count * 2) - 2)
		last_pipe(node);
	else
		default_pipe(node);
	*(node->pipe_index) += 2;
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
