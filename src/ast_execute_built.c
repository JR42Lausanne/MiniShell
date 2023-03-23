/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:38 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/23 11:46:37 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static void	restore_fds(t_ast_node *node, int out_fd, int in_fd)
{
	if (node->redir_fd_in != -1)
	{
		if (dup2(in_fd, STDIN_FILENO) == -1)
			perror("dup in error");
		close(in_fd);
	}
	if (node->redir_fd_out != -1)
	{
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			perror("dup out error");
		close(out_fd);
	}
}

void	ast_execute_built(t_ast_node *node)
{
	t_builtin_cont	*content;
	int				status;
	int				out_fd;
	int				in_fd;

	if (node->pipe_count > 0)
		node->pid = fork();
	if (node->pid == 0)
	{
		ast_node_redirect(node);
		content = (t_builtin_cont *) node->content;
		status = content->func_pointer(content->args);
		exit(status);
	}
	else if (node->pid == -1)
	{
		out_fd = dup(STDOUT_FILENO);
		in_fd = dup(STDIN_FILENO);
		ast_node_redirect(node);
		content = (t_builtin_cont *) node->content;
		node->exit_status = content->func_pointer(content->args);
		restore_fds(node, out_fd, in_fd);
	}
}
