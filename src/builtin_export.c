/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:02 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/30 14:47:15 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtins.h"
#include "../include/libft.h"

int	var_name_len(char *var)
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

static	void	check_is_match(int arg_num, int *i, char **args)
{
	while (g_ms.env[*i] != NULL)
	{
		if (ft_strncmp(g_ms.env[*i], args[arg_num],
				max(var_name_len(g_ms.env[*i]),
					var_name_len(args[arg_num]))) == 0)
			break ;
		(*i)++;
	}	
}

int	builtin_export(char **args)
{	
	int	i;
	int	arg_num;
	int	status;

	arg_num = 0;
	status = 0;
	while (args[++arg_num])
	{
		i = 0;
		if (!is_valid_varname(args[arg_num]))
			status = 1;
		if (ft_strchr(args[arg_num], '='))
		{		
			check_is_match(arg_num, &i, args);
			if (i < MAX_ENV - 1)
			{
				if (g_ms.env[i])
					free(g_ms.env[i]);
				g_ms.env[i] = ft_strdup(args[arg_num]);
			}
		}
	}
	if (arg_num == 1)
		export_without_args();
	return (status);
}
