/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:04:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/28 19:08:50 by jlaiti           ###   ########.fr       */
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

void	ast_execute_cmd(t_ast_node *node)
{
	t_exe	*exe;

	exe->path = getenv("PATH");
	exe->path_bin = ft_split(exe->path, ':');
	exe->cmd_opt = ft_split(node->content, ' ');
	exe->cmd = get_cmd(exe->path_bin, exe->cmd_opt[0]);
	if (!exe->cmd)
	{
		free_exe(exe);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	execve(exe->cmd, exe->cmd_opt, (const *char) exe->path);
}
