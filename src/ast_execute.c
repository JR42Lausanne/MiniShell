/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 14:36:46 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include <stdlib.h>
#include <stdio.h>

void	ast_execute(t_ast_node *node)
{
	int	i;

	if (!node)
	{
		printf("node is NULL\n");
		return ;
	}
	if (node->type == AST_ROOT)
	{
		ast_execute(node->children[0]);
		return ;
	}
	//TODO specifics before calling childrens
	i = -1;
	while (++i < node->child_number)
	{
		ast_execute(node->children[i]);
	}
	if (i == 0 && node->type == AST_CMD)
		ast_execute_cmd(node);
	if (i == 0 && node->type == AST_BUILTIN)
		ast_execute_built(node);
}
