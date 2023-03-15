/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:36 by graux             #+#    #+#             */
/*   Updated: 2023/03/15 16:04:11 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/ast.h"
#include "../include/minishell.h"
#include "../include/execute.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	char		*line;
	t_token		**tokens;
	t_ast_node	*ast_root;

	(void) argc;
	(void) argv;
	ms_envsetup(envp);
	while (1)
	{
		line = readline("$> ");
		add_history(line);
		tokens = tokenize_input(line);
		//tokens_print(tokens);
		ast_root = ast_generate(tokens);
		//ast_print(ast_root, 0);
		ast_execute(ast_root);
		//ast_close(ast_root);
		(void) ast_close;
		ast_close_all_pipes(ast_root);
		//close(STDIN_FILENO);
		ast_wait(ast_root);
		//TODO free tokens and ast
		free(line);
	}
	return (0);
}
