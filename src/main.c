/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:36 by graux             #+#    #+#             */
/*   Updated: 2023/03/16 13:40:41 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/ast.h"
#include "../include/minishell.h"
#include "../include/builtins.h"
#include "../include/execute.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char *argv[], char *envp[])
{
	char			*line;
	t_token			**tokens;
	t_ast_node		*ast_root;

	(void) argc;
	(void) argv;
	ms_envsetup(envp);
	if (signal_setup() == -1)
		return (-1);
	while (1)
	{
		g_env[MAX_ENV] = "p";
		line = readline("$> ");
		if (!line)
			builtin_exit(NULL);
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		add_history(line);
		tokens = tokenize_input(line);
		tokens_print(tokens);
		//tokens_check_syntax(tokens);
		ast_root = ast_generate(tokens);
		ast_print(ast_root, 0);
		g_env[MAX_ENV] = "e";
		ast_execute(ast_root);
		ast_close_all_pipes(ast_root);
		ast_wait(ast_root);
		//TODO free tokens and ast
		free(line);
	}
	return (0);
}
