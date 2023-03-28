/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:15:56 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/28 16:26:29 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/minishell.h"

int	builtin_env(char **args)
{
	int		i;

	(void) args;
	i = 0;
	while (i < MAX_ENV && g_ms.env[i])
	{
		printf("%s\n", g_ms.env[i]);
		i++;
	}
	return (0);
}
