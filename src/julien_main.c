/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julien_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:52 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/02 14:07:01 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/execute.h"
#include "../include/tokenizer.h"
#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_ast_node		*ast;
	t_ast_node		*child;
	t_builtin_cont	*cont;
	char			*arg[] = {"unset", "a"};

	(void) argc;
	(void) argv;
	ms_envsetup(envp);
	ast = malloc(sizeof(t_ast_node));
	ast->type = AST_ROOT;
	ast->child_number = 1;
	ast->content = NULL;
	child = malloc(sizeof(t_ast_node));
	child->type = AST_BUILTIN;
	child->child_number = 0;
	cont = malloc(sizeof(t_builtin_cont));
	cont->func_pointer = builtin_export;
	cont->args = malloc(3 * sizeof(char *));
	cont->args[0] = "export";
	cont->args[1] = "a=toto";
	cont->args[2] = NULL;
	child->content = cont;
	ast->children = malloc(sizeof(t_ast_node *));
	ast->children[0] = child;
	ast_execute(ast);
	builtin_env(NULL);
	builtin_unset(arg);
	builtin_env(NULL);
	return (0);
}
