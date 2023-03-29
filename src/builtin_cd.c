/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:05:21 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/29 15:17:24 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"
#include <limits.h>

static void	change_old_pwd(char *old_pwd)
{
	char	*export_args[3];

	export_args[0] = "export";
	export_args[1] = ft_strjoin("OLDPWD=", old_pwd);
	export_args[2] = NULL;
	builtin_export(export_args);
	free(export_args[1]);
	free(old_pwd);
}

static	void	export_new_arg(char **export_args, char *old_pwd)
{
	builtin_export(export_args);
	change_old_pwd(old_pwd);
}

int	builtin_cd(char **args)
{
	int		status;
	char	*old_pwd;
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
		old_pwd = ms_getenv_cont("PWD");
		export_args[0] = "export";
		export_args[1] = ft_strjoin("PWD=", current_path);
		export_args[2] = NULL;
		export_new_arg(export_args, old_pwd);
		free(export_args[1]);
	}	
	return (0);
}
