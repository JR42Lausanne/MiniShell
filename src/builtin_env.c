/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:15:56 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 20:35:33 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/minishell.h"

int	builtin_env(char **args)
{
	int		i;
	char	**env;

	env = g_env;
	(void) args;
	i = 0;
	while (env[i])
	{
		printf("%s", env[i]);
		i++;
	}
	if (!env)
		return (1);
	return (0);
}
