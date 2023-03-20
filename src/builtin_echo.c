/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:08:45 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/20 16:25:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/libft.h"
#include <stdio.h>

int	builtin_echo(char **args)
{
	int	i;

	if (!args[1])
	{
		printf("\n");
		return (0);
	}
	i = 0;
	if (ft_strncmp(args[1], "-n", 2) == 0)
		i++;
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	if (!(ft_strncmp(args[1], "-n", 2) == 0))
		printf("\n");
	return (0);
}
