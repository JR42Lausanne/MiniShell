/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:02 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/27 17:14:39 by graux            ###   ########.fr       */
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

static int	is_valid_varname(char *var_name)
{
	int			i;

	i = -1;
	if (ft_isdigit(var_name[++i]))
	{
		error_put(var_name, "not a valid indentifier");
		return (0);
	}
	while (var_name[i] && var_name[i] != '=')
	{
		if (var_name[i] != '_' && !ft_isalnum(var_name[i]))
		{
			error_put(var_name, "not a valid indentifier");
			return (0);
		}
		i++;
	}
	return (i > 0);
}

//TODO export without agrs -> declare -x machin bidule
int	builtin_export(char **args)
{	
	int	i;
	int	arg_num;
	int	status;

	arg_num = 0;
	status = 0;
	while (args[++arg_num])
	{
		i = -1;
		if (!is_valid_varname(args[arg_num]))
			status = 1;
		if (ft_strchr(args[arg_num], '='))
		{		
			while (g_env[++i] != NULL)
			{
				if (ft_strncmp(g_env[i], args[arg_num],
						max(var_name_len(g_env[i]),
							var_name_len(args[arg_num]))) == 0)
					break ;
			}
			if (i < MAX_ENV - 1)
			{
				if (g_env[i])
					free(g_env[i]);
				g_env[i] = ft_strdup(args[arg_num]);
			}
		}
	}
	return (status);
}
