/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:17:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/27 16:33:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtins.h"
#include "../include/libft.h"

static int	var_name_len(char *var)
{
	int	size;

	if (!var)
		return (0);
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

static void	remove_from_env(int pos)
{
	while (pos < MAX_ENV - 1)
	{
		g_env[pos] = g_env[pos + 1];
		pos++;
	}
	g_env[MAX_ENV - 1] = NULL;
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
	while (var_name[i])
	{
		if (var_name[i] != '_' && !ft_isalnum(var_name[i]))
		{
			error_put(var_name, "not a valid indentifier");
			return (0);
		}
		i++;
	}
	return (1);
}

int	builtin_unset(char	**args)
{
	int	i;
	int	arg_num;
	int	status;

	if (args && !args[1])
		return (0);
	arg_num = 0;
	status = 0;
	while (args[++arg_num])
	{
		if (!is_valid_varname(args[arg_num]))
			status = 1;
		i = -1;
		while (++i < MAX_ENV)
		{
			if (!g_env[i])
				break ;
			if (ft_strncmp(g_env[i], args[arg_num], max(var_name_len(g_env[i]),
						var_name_len(args[arg_num]))) == 0)
			{	
				free(g_env[i]);
				remove_from_env(i);
				break ;
			}
		}
	}
	return (status);
}	
