/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:38 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/21 18:22:10 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

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
		content = (t_builtin_cont *) node->content;
		node->exit_status = content->func_pointer(content->args);
	}
}
