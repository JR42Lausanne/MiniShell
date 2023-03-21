/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:04:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/21 18:56:47 by graux            ###   ########.fr       */
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
	if (ft_strnstr(cmd, "./", ft_strlen(cmd)))
		return (1);
	else if (ft_strnstr(cmd, "../", ft_strlen(cmd)))
		return (1);
	return (0);
}

static int	is_regular(char *cmd)
{
	struct stat	file_stat;

	stat(cmd, &file_stat);
	return (!S_ISDIR(file_stat.st_mode));
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
		if (access(command, X_OK) == 0 && is_regular(command))
			return (command);
		free(command);
	}
	return (NULL);
}

void	ast_execute_cmd(t_ast_node *node)
{
	t_cmd_cont	*content;
	char		*cmd_full_path;

	content = (t_cmd_cont *) node->content;
	cmd_full_path = get_cmd(content->cmd_name);
	if (!cmd_full_path)
	{
		perror(content->cmd_name);
		node->exit_status = 127;
		return ;
	}
	node->pid = fork();
	if (node->pid == 0)
	{
		ast_node_redirect(node);
		execve(cmd_full_path, content->args, g_env);
		perror(cmd_full_path);
	}
	//free(cmd_full_path); //Maybe free after wait
}
