/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/30 12:41:12 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"
#include "../include/builtins.h"
#include <stdlib.h>
#include <stdio.h>

static void	export_last_arg(t_ast_node *node)
{
	char	*export_args[3];
	char	**args;
	int		i;

	export_args[0] = "export";
	args = NULL;
	if (node->type == AST_CMD)
		args = ((t_cmd_cont *)node->content)->args;
	else if (node->type == AST_BUILTIN)
		args = ((t_builtin_cont *)node->content)->args;
	if (!args)
		return ;
	i = 0;
	while (args[i])
		i++;
	export_args[1] = ft_strjoin("_=", args[i - 1]);
	export_args[2] = NULL;
	builtin_export(export_args);
	free(export_args[1]);
}

void	ast_execute(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == AST_ROOT)
	{
		ast_execute(node->children[0]);
		return ;
	}
	if (node->type == AST_PIPE)
		ast_handle_pipe(node);
	ast_execute(node->children[0]);
	ast_execute(node->children[1]);
	if (node->type == AST_CMD)
		ast_execute_cmd(node);
	else if (node->type == AST_BUILTIN)
		ast_execute_built(node);
	export_last_arg(node);
}
