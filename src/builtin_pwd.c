/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:11:33 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/05 14:19:51 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int	builtin_pwd(char **args)
{
	char	cwd[NAME_MAX];

	(void) args;
	getcwd(cwd, NAME_MAX);
	printf("%s\n", cwd);
	return (0);
}
