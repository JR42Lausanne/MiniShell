/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:39:02 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/29 11:47:20 by jlaiti           ###   ########.fr       */
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

static void	export_without_args(void)
{
	int	i;

	i = -1;
	while (++i < MAX_ENV && g_ms.env[i])
	{
		printf("declare -x ");
		printf("%.*s", var_name_len(g_ms.env[i]), g_ms.env[i]);
		printf("=\"%s\"\n", g_ms.env[i] + var_name_len(g_ms.env[i]) + 1);
	}
}
//TODO = modif 
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
			while (g_ms.env[++i] != NULL)
			{
				if (ft_strncmp(g_ms.env[i], args[arg_num],
						max(var_name_len(g_ms.env[i]),
							var_name_len(args[arg_num]))) == 0)
					break ; //TODO put in while loop
			}
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
