/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:30:08 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/30 12:54:25 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"
#include <stdlib.h>
#include <limits.h>

static int	check_too_long(char *arg)
{
	long	l_val;

	l_val = ft_atol(arg);
	if (l_val < INT_MIN || l_val > INT_MAX)
		return (1);
	return (0);
}

int	check_numeric(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			continue ;
		if (!ft_isdigit(arg[i]))
		{
			error_put("exit", "numeric argument required");
			return (255);
		}
	}
	if (check_too_long(arg))
	{
		error_put("exit", "numeric argument required");
		return (255);
	}
	return (0);
}

int	builtin_exit(char **args)
{
	int	status;

	ft_putstr_fd("exit\n", 2);
	if (!args)
		exit(0);
	if (args[1])
	{
		status = check_numeric(args[1]);
		if (status == 0)
		{
			if (!args[2])
				status = ft_atoi(args[1]);
			else
			{
				error_put("exit", "too many arguments");
				return (1);
			}
		}
	}
	else
		status = 0;
	exit(status & 0xFF);
	return (1);
}
