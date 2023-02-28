/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/28 17:35:48 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include <stdlib.h>
#include <stdio.h>

void	ast_execute(t_ast_node *node)
{
	t_exe	*exe;

	exe->path = getenv("PATH");
	exe->cmd_path = check_path(exe->path);
}

static void	ast_execute_test(t_ast_node *node)
{
	int	i;

	if (!node)
	{
		printf("node is NULL\n");
		return ;
	}
	if (node->type == AST_ROOT)
		ast_execute(node->children[0]);
	//TODO specifics before calling childrens
	i = -1;
	while (++i < node->child_number)
		ast_execute(node->children[i]);
	if (i == 0 && node->type == AST_CMD)
		ast_execute_cmd(node);
	if (i == 0 && node->type == AST_BUILTIN)
		ast_execute_built(node);
}
