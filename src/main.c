/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:23:40 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 13:29:29 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_token		*tokens;
	t_ast_node	*ast;

	(void) argc;
	(void) argv;
	(void) envp;
	input = NULL;
	while (1)
	{
		input = readline("$>");
		tokens = tokenize_input(&input);
		ast = ast_generate(tokens);
		ast_execute(ast);
		// TODO cleanup tokens and ast
		free(input);
	}
}
