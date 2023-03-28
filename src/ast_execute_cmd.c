/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:04:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/28 16:21:20 by graux            ###   ########.fr       */
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

static int	check_access(char *cmd)
{
	struct stat	file_stat;

	if (!cmd)
		return (127);
	stat(cmd, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		return (126);
	return (0);
}

static char	*get_cmd(char *cmd)
{
	char	*tmp;
	char	*command;
	char	*env_path;
	char	**path;
	int		i;

	if (check_relative(cmd))
		return (ft_strdup(cmd));
	env_path = ms_getenv_cont("PATH");
	if (!env_path)
		return (NULL);
	path = ft_split(env_path, ':');
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, X_OK) == 0 && !check_access(command))
			return (command);
		free(command);
	}
	return (NULL);
}

static char	*cmd_exec_err_str(int status)
{
	if (status == 127)
		return ("command not found");
	else if (status == 126)
		return ("is a directory");
	else
		return ("unknow cmd error");
}

void	ast_execute_cmd(t_ast_node *node)
{
	t_cmd_cont	*content;
	char		*cmd_full_path;
	int			access_status;

	content = (t_cmd_cont *) node->content;
	cmd_full_path = get_cmd(content->cmd_name);
	access_status = check_access(cmd_full_path);
	if (access_status)
	{
		error_put(content->cmd_name, cmd_exec_err_str(access_status));
		node->exit_status = access_status;
		return ;
	}
	node->pid = fork();
	if (node->pid == 0)
	{
		ast_node_redirect(node);
		execve(cmd_full_path, content->args, g_ms.env);
	}
}
