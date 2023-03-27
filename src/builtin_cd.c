/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:05:21 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/24 17:05:40 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"
#include <limits.h>

int	builtin_cd(char **args)
{
	int		status;
	char	current_path[NAME_MAX];
	char	*export_args[3];

	if (args && !args[1])
		status = chdir(ms_getenv_cont("HOME"));
	else
		status = chdir(args[1]);
	if (status == -1)
	{
		perror(args[1]);
		return (1);
	}
	else
	{
		getcwd(current_path, NAME_MAX);
		export_args[0] = "export";
		export_args[1] = ft_strjoin("PWD=", current_path);
		export_args[2] = NULL;
		builtin_export(export_args);
		free(export_args[1]);
	}	
	return (0);
}
