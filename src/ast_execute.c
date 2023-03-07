/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 10:11:44 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include <stdlib.h>
#include <stdio.h>

void	ast_execute(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == AST_ROOT)
	{
		ast_execute(node->children[0]);
		return ;
	}
	//TODO specifics before calling childrens
	ast_execute(node->children[0]);
	ast_execute(node->children[1]);
	if (node->type == AST_CMD)
		ast_execute_cmd(node);
	else if (node->type == AST_BUILTIN)
		ast_execute_built(node);
}
