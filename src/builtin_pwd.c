/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:14:14 by graux             #+#    #+#             */
/*   Updated: 2023/02/24 16:20:52 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include <stdlib.h>
#include <stdio.h>

void	builtin_pwd(void)
{
	char	*working_dir;

	working_dir = getenv("PWD");
	//TODO change to ft_printf
	printf("%s\n", working_dir);
	free(working_dir);
}
