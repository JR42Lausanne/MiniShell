/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:02 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 16:20:38 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtins.h"
#include "../include/libft.h"

static int	var_name_len(char *var)
{
	int	size;

	size = 0;
	while (var[size] && var[size] != '=')
		size++;
	return (size);
}

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

//TODO check exporting same var multiple times and mulitple var
int	builtin_export(char **args)
{	
	int	i;

	if (args && !args[1])
		return (1);
	i = -1;
	if (ft_strchr(args[1], '='))
	{		
		while (g_env[++i] != NULL)
		{
			if (ft_strncmp(g_env[i], args[1], max(var_name_len(g_env[i]),
						var_name_len(args[1]))) == 0)
				break ;
		}
		if (i < MAX_ENV - 1)
		{
			if (g_env[i])
				free(g_env[i]);
			g_env[i] = ft_strdup(args[1]);
			return (0);
		}
		printf("No more room in env\n");
		return (1);
	}
	printf("Invalid variable\n");
	return (1);
}
