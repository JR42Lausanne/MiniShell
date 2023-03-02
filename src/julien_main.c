/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julien_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:52 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/02 11:41:45 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/execute.h"
#include "../include/tokenizer.h"
#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"

static int	env_setup(char **envp)
{
	int	i;

	i = 0;
	while (i < MAX_ENV && envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	if (!envp[i])
		return (1); //TODO free
	while (i < MAX_ENV)
		g_env[i++] = NULL;
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ast_node		*ast;
	t_ast_node		*child;
	t_builtin_cont	*cont;

	(void) argc;
	(void) argv;
	env_setup(envp);
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
	cont->args[1] = "test=some value";
	cont->args[2] = NULL;
	child->content = cont;
	ast->children = malloc(sizeof(t_ast_node *));
	ast->children[0] = child;
	ast_execute(ast);
	builtin_env(NULL);
	return (0);
}
