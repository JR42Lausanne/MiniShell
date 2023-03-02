/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guilhem_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:52:35 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 12:20:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_token		**tokens;
	t_tokenizer	*toker;

	ms_envsetup(envp);
	if (argc != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	printf("%s\n", argv[1]);
	toker = tokenizer_create(argv[1]);
	tokens = tokenizer_parse(toker);
	tokens_print(tokens);
	return (0);
}
