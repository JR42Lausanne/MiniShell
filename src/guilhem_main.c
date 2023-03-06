/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guilhem_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:52:35 by graux             #+#    #+#             */
/*   Updated: 2023/03/04 15:41:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/ast.h"
#include "../include/minishell.h"
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_token		**tokens;
	t_ast_node	*ast_root;

	ms_envsetup(envp);
	if (argc != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	printf("%s\n", argv[1]);
	tokens = tokenize_input(argv[1]);
	tokens_print(tokens);
	printf("\nAST generation:\n");
	ast_root = ast_generate(tokens); //TODO free tokens
	printf("\nAST Generated:\n");
	ast_print(ast_root, 0);
	return (0);
}
