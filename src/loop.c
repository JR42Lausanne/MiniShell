/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:43:01 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/26 16:00:19 by jlaiti           ###   ########.fr       */
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

void	loop(t_token **tokens, t_ast_node *ast_root, int *status)
{
	char prompt[PROMPT_SIZE + 4];

	while (1)
	{
		g_env[MAX_ENV] = "p";
		gen_prompt(prompt, status);
		line = readline(prompt);
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
		status = tokens_check_syntax(tokens) - 1;
		if (status + 1)
		{
			//tokens_destroy(tokens);
			continue ;
		}
		free(line);
		ast_root = ast_generate(tokens);
		show_debug(argc, argv, tokens, ast_root, 'a');
		g_env[MAX_ENV] = "e";
		ast_execute(ast_root);
		ast_close_all_pipes(ast_root);
		ast_close_all_redirs(ast_root);
		status = ast_wait(ast_root);
		//TODO free tokens and ast
	}
}
