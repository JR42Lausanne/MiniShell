/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:30:08 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/16 13:24:19 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/libft.h"
#include <stdlib.h>

int	check_numeric(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (255);
	}
	return (0);
}

//TODO error handling for invalid inputs
int	builtin_exit(char **args)
{
	int	status;

	printf("exit\n");
	if (!args)
		exit(0); //-> when ctrl-D is pressed //TODO free everything
	if (args[1])
	{
		status = check_numeric(args[1]);
		if (status == 0)
		{
			if (!args[2])
				status = ft_atoi(args[1]);
			else
			{
				printf("Too many args\n"); //TODO error handling
				return (1);
			}
		}
	}
	else
		status = 0;
	exit(status & 0xFF);
	return (1);
}
