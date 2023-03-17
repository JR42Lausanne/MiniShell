/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:02 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/17 11:33:56 by graux            ###   ########.fr       */
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

//TODO fix it, it does not work
int	builtin_export(char **args)
{	
	int	i;
	int	arg_num;

	arg_num = 0;
	while (args[++arg_num])
	{
		i = -1;
		if (ft_strchr(args[arg_num], '='))
		{		
			while (g_env[++i] != NULL)
			{
				if (ft_strncmp(g_env[i], args[arg_num],
						max(var_name_len(g_env[i]),
							var_name_len(args[arg_num]))) == 0)
				{
					fprintf(stderr, "MATCH FOUND\n");
					break ;
				}
			}
			if (i < MAX_ENV - 1)
			{
				fprintf(stderr, "ADDING %s TO ENV at pos %d\n", args[arg_num], i);
				if (g_env[i])
					free(g_env[i]);
				g_env[i] = ft_strdup(args[arg_num]);
			}
		}
	}
	return (0);
}
