/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:36 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 13:40:58 by graux            ###   ########.fr       */
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

static void	show_debug(int argc, char **argv, t_token **tokens, t_ast_node *ast_root, char c)
{
	if (argc == 2)
	{
		if (c == 't')
			printf("-------------------- DEBUG --------------------\n");
		if ((argv[1][0] == 't' || argv[1][1] == 't') && c == 't')
		{
			printf("\t\t---> TOKENS <---\n");
			tokens_print(tokens);
		}
		if ((argv[1][0] == 'a' || argv[1][1] == 'a') && c == 'a')
		{
			printf("\t\t-----> AST <----\n");
			ast_print(ast_root, 0);
		}
		if (c == 'a')
			printf("------------------- DEBUG END -----------------\n");
	}
}

static int	not_interactive(char *cmd)
{
	t_token			**tokens;
	t_ast_node		*ast_root;

	tokens = tokenize_input(cmd, 0);
	ast_root = ast_generate(tokens);
	ast_execute(ast_root);
	ast_close_all_pipes(ast_root);
	ast_wait(ast_root);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char			*line;
	t_token			**tokens;
	t_ast_node		*ast_root;
	int				status;

	ms_envsetup(envp);
	if (argc == 3 && !ft_strncmp(argv[1], "-c", 3))
		exit(not_interactive(argv[2]));
	if (signal_setup() == -1)
		return (-1);
	status = 0;
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
		tokens = tokenize_input(line, status);
		show_debug(argc, argv, tokens, ast_root, 't');
		//tokens_check_syntax(tokens);
		ast_root = ast_generate(tokens);
		show_debug(argc, argv, tokens, ast_root, 'a');
		g_env[MAX_ENV] = "e";
		ast_execute(ast_root);
		ast_close_all_pipes(ast_root);
		ast_wait(ast_root);
		//TODO free tokens and ast
		free(line);
	}
	return (0);
}
