/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julien_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:52 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 14:48:44 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/execute.h"
#include "../include/tokenizer.h"
#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*args[2];

	args[0] = "cd";
	if (argc == 2)
		args[1] = argv[1];
	else
		args[1] = NULL;
	ms_envsetup(envp);
	builtin_cd(args);
	return (0);
}
