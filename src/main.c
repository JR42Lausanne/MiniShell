/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:36 by graux             #+#    #+#             */
/*   Updated: 2023/03/29 14:45:05 by jlaiti           ###   ########.fr       */
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
	int				status;

	tokens = tokenize_input(cmd, 0);
	status = tokens_check_syntax(tokens) - 1;
	if (status + 1)
		return (status);
	ast_root = ast_generate(tokens);
	ast_execute(ast_root);
	ast_close_all_pipes(ast_root);
	ast_close_all_redirs(ast_root);
	status = ast_wait(ast_root);
	return (status);
}

static void	gen_prompt(char prompt[PROMPT_SIZE], int status)
{
	int		pos;
	char	*str;
	int		offset;

	printf("%s", GREEN);
	prompt[0] = '(';
	pos = 1;
	str = ft_itoa(status);
	ft_memcpy(prompt + pos, str, ft_strlen(str));
	pos += ft_strlen(str);
	free(str);
	prompt[pos] = ')';
	prompt[pos + 1] = ' ';
	pos += 2;
	str = ms_getenv_cont("PWD");
	offset = 0;
	if (ft_strlen(str) + pos > PROMPT_SIZE - 5)
	{
		offset = ft_strlen(str) - (PROMPT_SIZE - 5 - pos) + 4;
		ft_memcpy(prompt + pos, "/...", 4);
		pos += 4;
	}
	ft_memcpy(prompt + pos, str + offset, ft_strlen(str + offset));
	pos += ft_strlen(str + offset);
	free(str);
	ft_memcpy(prompt + pos, "\n$> ", 4);
	ft_memcpy(prompt + pos + 4, RESET, 5);
}

int	main(int argc, char *argv[], char *envp[])
{
	char					*line;
	t_token					**tokens;
	t_ast_node				*ast_root;
	char					prompt[PROMPT_SIZE + 4];

	if (!ms_envsetup(envp))
		return (-1);
	if (argc == 3 && !ft_strncmp(argv[1], "-c", 3))
		exit(not_interactive(argv[2]));
	while (1)
	{
		g_ms.env[MAX_ENV] = "p";
		gen_prompt(prompt, g_ms.status);
		line = readline(prompt);
		if (!line)
			builtin_exit(NULL);
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		add_history(line);
		tokens = tokenize_input(line, g_ms.status);
		show_debug(argc, argv, tokens, ast_root, 't');
		g_ms.status = tokens_check_syntax(tokens) - 1;
		if (g_ms.status + 1)
		{
			//tokens_destroy(tokens);
			continue ;
		}
		g_ms.env[MAX_ENV] = "e";
		ast_root = ast_generate(tokens);
		show_debug(argc, argv, tokens, ast_root, 'a');
		ast_execute(ast_root);
		ast_close_all_pipes(ast_root);
		ast_close_all_redirs(ast_root);
		g_ms.status = ast_wait(ast_root);
		//TODO free tokens and ast
	}
	return (0);
}
