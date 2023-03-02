/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:02 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/02 11:39:25 by jlaiti           ###   ########.fr       */
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

//TODO check exporting same var multiple times and mulitple var
int	builtin_export(char **args)
{	
	int	i;

	i = -1;
	if (ft_strchr(args[1], '='))
	{		
		while (g_env[++i] != NULL)
		{
			if (ft_strncmp(g_env[i], args[1], var_name_len(args[1])) == 0)
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
	//check if args[1] contains an =
	//check if the variable is already set in g_env
	//if it is replace g_env[?] where it matched
