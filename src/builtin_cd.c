/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:05:21 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/06 10:42:33 by jlaiti           ###   ########.fr       */
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
}

static	void	export_new_var(char **export_args, char *old_pwd)
{
	builtin_export(export_args);
	change_old_pwd(old_pwd);
}

static int	try_cd(char **args)
{
	if (args && !args[1])
	{
		if (chdir(ms_getenv_cont("HOME")) == -1)
		{
			error_put(args[0], "HOME not set");
			return (0);
		}
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(args[1]);
			return (0);
		}
	}
	return (1);
}

int	builtin_cd(char **args)
{
	char	old_pwd[NAME_MAX];
	char	current_path[NAME_MAX];
	char	*export_args[3];

	getcwd(old_pwd, NAME_MAX);
	if (try_cd(args))
	{
		getcwd(current_path, NAME_MAX);
		export_args[0] = "export";
		export_args[1] = ft_strjoin("PWD=", current_path);
		export_args[2] = NULL;
		export_new_var(export_args, old_pwd);
		free(export_args[1]);
		return (0);
	}	
	return (1);
}
