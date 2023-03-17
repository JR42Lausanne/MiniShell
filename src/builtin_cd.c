/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:06:09 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/17 17:02:08 by graux            ###   ########.fr       */
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
	}	
	return (0);
}
// si argv[0] == cd fonction ok;
//prendre le le home path de l'env et mettre dans PWD si arg[1] est NULL ou si arg[1]~;
//si ../dans agv[1][i] supprimer l'avant dernier /
//si ./ ou / prendre le path absolue.
//chdir 
