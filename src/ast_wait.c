/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:11:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/15 17:13:48 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_wait(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->pid != -1 && (node->type == AST_CMD || node->type == AST_BUILTIN))
		waitpid(node->pid, NULL, 0);
	ast_wait(node->children[0]);
	ast_wait(node->children[1]);
}
