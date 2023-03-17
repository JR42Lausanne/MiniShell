/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:38 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/17 12:50:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static int	check_built_fork(void *cont)
{
	char	*name;

	if (!cont)
		return (0);
	name = ((t_builtin_cont *)cont)->args[0];
	if (!name)
		return (0);
	if (ft_strncmp(name, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(name, "env", 3) == 0)
		return (1);
	else
		return (0);
}

void	ast_execute_built(t_ast_node *node)
{
	t_builtin_cont	*content;
	int				status;

	if (check_built_fork(node->content))
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
		status = content->func_pointer(content->args);
	}
}
