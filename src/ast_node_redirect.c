/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:44 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 16:47:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_close_all_pipes(t_ast_node *node)
{
	int	i;

	if (!node)
		return ;
	i = -1;
	while (++i < node->pipe_count * 2)
		close(node->all_pipes[i]);
}

void	ast_close_all_redirs(t_ast_node *node)
{
	int	i;

	if (!node)
		return ;
	i = -1;
	while (node->all_redirs[++i] != -2)
		close(node->all_redirs[i]);
}

int	ast_node_redirect(t_ast_node *node)
{
	if (!node)
		return (1);
	dup2(node->fd_in, STDIN_FILENO);
	dup2(node->fd_out, STDOUT_FILENO);
	if (node->redir_fd_in != -1)
		dup2(node->redir_fd_in, node->fd_in);
	if (node->redir_fd_out != -1)
		dup2(node->redir_fd_out, node->fd_out);
	ast_close_all_pipes(node);
	ast_close_all_redirs(node);
	return (0);
}
