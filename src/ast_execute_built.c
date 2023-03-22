/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:38 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/22 17:23:48 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
/*
static void	chang_last_redir(int *redirs)
{
	int	i;

	i = -1;
	while (redirs[++i] != -2)
		;
	redirs[i - 1] = STDOUT_FILENO;
}
*/

void	ast_execute_built(t_ast_node *node)
{
	t_builtin_cont	*content;
	int				status;

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
		ast_node_redirect(node);
		content = (t_builtin_cont *) node->content;
		node->exit_status = content->func_pointer(content->args);
		if (node->redir_fd_in != -1)
			dup2(STDIN_FILENO, node->redir_fd_in);
		if (node->redir_fd_out != -1)
		{
			dup2(STDOUT_FILENO, node->redir_fd_out);
			//chang_last_redir(node->all_redirs);
		}
	}
}
