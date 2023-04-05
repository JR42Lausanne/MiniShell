/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:36 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 19:19:23 by graux            ###   ########.fr       */
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

/*
static void	show_debug(int argc, char **argv, t_token **tokens,
		t_ast_node *ast_root, char c)
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
*/

static int	line_reading(char **line)
{
	char	prompt[PROMPT_SIZE + 4];

	g_ms.env[MAX_ENV] = "p";
	ms_gen_prompt(prompt, g_ms.status);
	*line = readline(prompt);
	if (!(*line))
		builtin_exit(NULL);
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		return (0);
	}
	add_history(*line);
	return (1);
}

static int	tokens_parse(t_token ***tokens, char *line)
{
	*tokens = tokenize_input(line, g_ms.status);
	g_ms.status = tokens_check_syntax(*tokens) - 1;
	if (g_ms.status + 1)
	{
		tokens_destroy(*tokens);
		return (0);
	}
	return (1);
}

static int	check_valid_ast(t_ast_node *node, int depth)
{
	static int	valid;

	if (!node)
		return (0);
	if (depth == 0)
		valid = 1;
	if (node->type == AST_ROOT)
		check_valid_ast(node->children[0], depth + 1);
	else
	{
		check_valid_ast(node->children[0], depth + 1);
		check_valid_ast(node->children[1], depth + 1);
	}
	if (node->type == AST_INVALID)
		valid = 0;
	return (valid);
}

static int	ast_parse(t_ast_node **ast_root, t_token **tokens)
{
	*ast_root = ast_generate(tokens);
	if (!check_valid_ast(*ast_root, 0))
	{
		g_ms.status = 1;
		ast_node_destroy(*ast_root);
		tokens_destroy(tokens);
		return (0);
	}
	tokens_destroy(tokens);
	return (1);
}

//TODO invalid syntax for && and || ANNNNNND ()
int	main(int argc, char *argv[], char *envp[])
{
	char					*line;
	t_token					**tokens;
	t_ast_node				*ast_root;

	(void) argv;
	(void) argc;
	if (!ms_envsetup(envp))
		return (-1);
	while (1)
	{
		if (!line_reading(&line))
			continue ;
		if (!tokens_parse(&tokens, line))
			continue ;
		if (!ast_parse(&ast_root, tokens))
			continue ;
		ast_execute(ast_root);
		ast_close_all_pipes(ast_root);
		ast_close_all_redirs(ast_root);
		g_ms.status = ast_wait(ast_root);
		if (*g_ms.env[MAX_ENV] == 'p')
			g_ms.status = 130;
		ast_node_destroy(ast_root);
	}
	return (0);
}
