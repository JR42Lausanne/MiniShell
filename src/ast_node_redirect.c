/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:44 by graux             #+#    #+#             */
/*   Updated: 2023/03/15 16:25:15 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_close_all_pipes(t_ast_node *node)
{
	int	i;

	i = -1;
	while (++i < node->pipe_count * 2)
	{
		close(node->all_pipes[i]);
		fprintf(stderr, "closing: %d\n", node->all_pipes[i]);
	}
}

int	ast_node_redirect(t_ast_node *node)
{
	if (!node)
		return (1);
	dup2(node->fd_in, STDIN_FILENO);
	dup2(node->fd_out, STDOUT_FILENO);
	ast_close_all_pipes(node);
	/*
	if (node->fd_to_close[0] != -1)
		close(node->fd_to_close[0]);
	if (node->fd_to_close[1] != -1)
		close(node->fd_to_close[1]);
	if (node->fd_to_close[2] != -1)
		close(node->fd_to_close[2]);
	if (node->fd_to_close[3] != -1)
		close(node->fd_to_close[3]);
		*/
	return (0);
}
