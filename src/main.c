/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:36 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 14:16:15 by graux            ###   ########.fr       */
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
	prompt[pos++] = ')';
	prompt[pos++] = ' ';
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
	ft_memcpy(prompt + pos, RESET "\n$> ", 9);
}

static int	line_reading(char **line)
{
	char	prompt[PROMPT_SIZE + 4];

	g_ms.env[MAX_ENV] = "p";
	gen_prompt(prompt, g_ms.status);
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

//TODO only redir
//TODO redir and pipes
//TODO redirs permissions
//TODO check _ env variable (ex a=dlksjflks as last arg)
//TODO pwd
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
		ast_root = ast_generate(tokens);
		ast_execute(ast_root);
		ast_close_all_pipes(ast_root);
		ast_close_all_redirs(ast_root);
		g_ms.status = ast_wait(ast_root);
		tokens_destroy(tokens);
		ast_node_destroy(ast_root);
	}
	return (0);
}
