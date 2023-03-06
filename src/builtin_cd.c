/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim builtin_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:36:04 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/06 11:20:14 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/minishell.h"

int	builtin_cd(char **args)
{
	char	*current_path;
	char	*home_path;

	current_path = ms_getenv("PWD");
	home_path = ms_getenv("HOME");
	if (args && !args[1])
		return (1);
	
	
}
