/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:17:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 16:27:25 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/minishell.h"
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

int	builtin_unset(char	**args)
{
	int	i;

	if (args && !args[1])
		return (1);
	i = 0;
	while (i < MAX_ENV)
	{
		if (!g_env[i])
			return (0);
		if (ft_strncmp(g_env[i], args[1], max(var_name_len(g_env[i]),
					var_name_len(args[1]))) == 0)
		{	
			free(g_env[i]);
			g_env[i] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}	
