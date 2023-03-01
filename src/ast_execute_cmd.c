/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:04:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 13:07:55 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/execute.h"
#include <stdio.h>
#include <stdlib.h>

static	void	free_exe(t_exe *exe)
{
	int	i;

	i = 0;
	while (exe->path_bin[i] != 0)
	{
		free(exe->path_bin[i]);
		i++;
	}
	i = 0;
	while (exe->cmd_opt[i] != 0)
	{
		free(exe->cmd_opt[i]);
		i++;
	}
	free(exe->path_bin);
	free(exe->cmd_opt);
}

static	char	*get_cmd(char	**path, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

static	void	*get_bin(t_exe *exe)
{
	exe->path = getenv("PATH");
	exe->path_bin = ft_split(exe->path, ':');
}

void	ast_execute_cmd(t_ast_node *node)
{
	t_exe		*exe;
	t_cmd_cont	*content;

	content = (t_cmd_cont *) node->content;
	get_bin(exe);
	exe->cmd_opt = content->args;
	exe->cmd = get_cmd(exe->path_bin, exe->cmd_opt[0]);
	if (!exe->cmd)
	{
		free_exe(exe);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	exe->pid1 = fork();
	if (exe->pid1 == 0)
	{
		execve(exe->cmd, exe->cmd_opt,getenv);
	}
}
