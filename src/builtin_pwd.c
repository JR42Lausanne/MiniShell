/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:11:33 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 20:15:06 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtins.h"
#include <stdio.h>
#include <stdlib.h>

//using g_env
int	builtin_pwd(char **args)
{
	char	*cwd;

	(void) args;
	cwd = ms_getenv("PWD");
	if (!cwd)
	{
		printf("You f*** up the environement PWD is not in it\n");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
