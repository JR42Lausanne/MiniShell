/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julien_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:52 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 18:09:33 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/execute.h"
#include "../include/tokenizer.h"
#include "../include/builtins.h"
#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_ast_node		*ast;
	t_ast_node		*child;
	t_builtin_cont	*cont;

	(void) argc;
	(void) argv;
	g_env = envp;
	ast = malloc(sizeof(t_ast_node));
	ast->type = AST_ROOT;
	ast->child_number = 1;
	ast->content = NULL;
	child = malloc(sizeof(t_ast_node));
	child->type = AST_BUILTIN;
	child->child_number = 0;
	cont = malloc(sizeof(t_builtin_cont));
	cont->func_pointer = builtin_echo;
	cont->args = malloc(4 * sizeof(char *));
	cont->args[0] = "echo";
	cont->args[1] = "test";
	cont->args[2] = "-n";
	cont->args[3] = NULL;
	child->content = cont;
	ast->children = malloc(sizeof(t_ast_node *));
	ast->children[0] = child;
	ast_execute(ast);
	return (0);
}
