/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handle_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:36:51 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 12:37:35 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static void	first_pipe(t_ast_node *node)
{
	node->children[0]->fd_in = STDIN_FILENO;
	node->children[0]->fd_out = node->all_pipes[*(node->pipe_index) + 1];
	if (node->pipe_count == 1)
	{
		node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
		node->children[1]->fd_out = STDOUT_FILENO;
	}
	else
	{
		node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
		node->children[1]->fd_out = node->all_pipes[*(node->pipe_index) + 3];
	}
}

static void	last_pipe(t_ast_node *node)
{
	node->children[0]->fd_in = node->fd_in;
	node->children[0]->fd_out = node->all_pipes[*(node->pipe_index) + 1];
	node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
	node->children[1]->fd_out = STDOUT_FILENO;
}

static void	default_pipe(t_ast_node *node)
{
	node->children[0]->fd_in = node->fd_in;
	node->children[0]->fd_out = node->all_pipes[*(node->pipe_index) + 1];
	node->children[1]->fd_in = node->all_pipes[*(node->pipe_index)];
	node->children[1]->fd_out = node->all_pipes[*(node->pipe_index) + 3];
}

void	ast_handle_pipe(t_ast_node *node)
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
