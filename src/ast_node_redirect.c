/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:44 by graux             #+#    #+#             */
/*   Updated: 2023/03/09 14:29:03 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

int	ast_node_redirect(t_ast_node *node)
{
	if (node->pipe_redir_out.fd_new != -1 && node->pipe_redir_out.fd_old != -1)
		dup2(node->pipe_redir_out.fd_new, node->pipe_redir_out.fd_old);
	if (node->pipe_redir_out.fd_pipe_other != -1)
		close(node->pipe_redir_out.fd_pipe_other);
	if (node->pipe_redir_in.fd_new != -1 && node->pipe_redir_in.fd_old != -1)
		dup2(node->pipe_redir_in.fd_new, node->pipe_redir_in.fd_old);
	if (node->pipe_redir_in.fd_pipe_other != -1)
		close(node->pipe_redir_in.fd_pipe_other);
	if (!node->redirs)
		return (0);
	return (0);
}
