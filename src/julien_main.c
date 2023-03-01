/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julien_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:52 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 15:38:53 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/execute.h"
#include "../include/tokenizer.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_ast_node	*ast;
	t_ast_node	*child;
	t_cmd_cont	*cont;

	(void) argc;
	(void) argv;
	ast = malloc(sizeof(t_ast_node));
	ast->type = AST_ROOT;
	ast->child_number = 1;
	ast->content = NULL;
	ast->env = NULL;
	child = malloc(sizeof(t_ast_node));
	child->type = AST_CMD;
	child->child_number = 0;
	cont = malloc(sizeof(t_cmd_cont));
	cont->cmd_name = "../script.sh";
	cont->args = malloc(2 * sizeof(char *));
	cont->args[0] = "../script.sh";
	cont->args[1] = NULL;
	child->content = cont;
	child->env = envp;
	ast->children = malloc(sizeof(t_ast_node *));
	ast->children[0] = child;
	ast_execute(ast);
	return (0);
}
