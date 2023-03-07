/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:38 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 18:42:11 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_execute_built(t_ast_node *node)
{
	t_builtin_cont	*content;
	pid_t			pid;
	int				status;

	pid = fork();
	if (pid == 0)
	{
		ast_node_redirect(node->redirs, node->pipe_redir);
		content = (t_builtin_cont *) node->content;
		status = content->func_pointer(content->args);
		exit(status);
	}
	else
		waitpid(pid, NULL, 0);
}
