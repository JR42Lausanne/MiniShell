/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:04:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/05 18:06:36 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/execute.h"
#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

static int	check_relative(char *cmd)
{
	if (ft_strncmp(cmd, "./", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd, "../", 3) == 0)
		return (1);
	else if (cmd[0] == '/')
		return (1);
	return (0);
}

static int	check_access(char *cmd, char *cmd_name)
{
	struct stat	file_stat;

	if (!cmd || !ft_strncmp(cmd_name, "..", 3) || !ft_strncmp(cmd_name, ".", 2)
		|| ft_strlen(cmd_name) == 0)
	{
		error_put(cmd_name, "command not found");
		return (127);
	}
	stat(cmd, &file_stat);
	printf("cmd: %s\n", cmd);
	if (S_ISDIR(file_stat.st_mode))
	{
		error_put(cmd_name, "is a directory");
		return (126);
	}
	if (access(cmd, X_OK) != 0)
	{
		error_put(cmd_name, "Permission denied");
		return (126);
	}
	return (0);
}

static char	*get_cmd(char *cmd)
{
	char	*command;
	char	*env_path;
	char	**path;
	int		i;

	command = NULL;
	if (check_relative(cmd))
		return (ft_strdup(cmd));
	env_path = ms_getenv_cont("PATH");
	if (!env_path)
		return (NULL);
	path = ft_split(env_path, ':');
	free(env_path);
	i = -1;
	while (path[++i])
	{
		command = get_full_cmd(path[i], cmd);
		if (access(command, F_OK) == 0)
			break ;
		free(command);
		command = NULL;
	}
	free_args(path);
	return (command);
}

void	ast_execute_cmd(t_ast_node *node)
{
	t_cmd_cont	*content;
	char		*cmd_full_path;
	int			access_status;

	content = (t_cmd_cont *) node->content;
	cmd_full_path = get_cmd(content->cmd_name);
	access_status = check_access(cmd_full_path, content->cmd_name);
	if (access_status)
	{
		node->exit_status = access_status;
		free(cmd_full_path);
		return ;
	}
	node->pid = fork();
	if (node->pid == 0)
	{
		ast_node_redirect(node);
		execve(cmd_full_path, content->args, g_ms.env);
	}
	free(cmd_full_path);
}
