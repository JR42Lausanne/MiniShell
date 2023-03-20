/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:08:45 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/20 16:51:20 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/libft.h"
#include <stdio.h>

static int	check_n(char *str)
{
	int	i;
	int	status;

	if (!str)
		return (0);
	i = -1;
	status = 0;
	while (str[++i])
	{
		if (i != 0 && str[i] == '-')
			return (0);
		else if (str[0] == '-' && str[i] == 'n')
			status = 1;
	}
	return (status);
}

int	builtin_echo(char **args)
{
	int	i;
	int	dash_n;

	if (!args[1])
	{
		printf("\n");
		return (0);
	}
	i = 0;
	dash_n = check_n(args[i + 1]);
	while (dash_n)
	{
		i++;
		dash_n = check_n(args[i + 1]);
	}
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	if (!check_n(args[1]))
		printf("\n");
	return (0);
}
