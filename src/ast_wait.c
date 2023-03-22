/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:11:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 11:53:48 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include <sys/wait.h>

static int	convert_stat_loc(int stat_loc)
{
	int	status;

	status = 231;
	if (WIFEXITED(stat_loc))
		status = WEXITSTATUS(stat_loc);
	else if (WIFSIGNALED(stat_loc))
		status = WTERMSIG(stat_loc) + 128;
	return (status);
}

int	ast_wait(t_ast_node *node)
{
	int	status;
	int	stat_loc;

	status = 69;
	if (!node)
		return (0);
	if (node->type == AST_ROOT)
	{
		status = ast_wait(node->children[0]);
		return (status);
	}
	if (node->pid != -1 && (node->type == AST_CMD || node->type == AST_BUILTIN))
	{
		waitpid(node->pid, &stat_loc, 0);
		status = convert_stat_loc(stat_loc);
	}
	else if (node->exit_status != -1)
		status = node->exit_status;
	ast_wait(node->children[0]);
	if (node->children[1])
		status = ast_wait(node->children[1]);
	return (status);
}
