/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:04:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 18:10:30 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/execute.h"
#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>

static int	check_relative(char *cmd)
{
	if (ft_strnstr(cmd, "./", ft_strlen(cmd)))
		return (1);
	else if (ft_strnstr(cmd, "../", ft_strlen(cmd)))
		return (1);
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
	env_path = getenv("PATH");
	path = ft_split(env_path, ':');
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
	t_cmd_cont	*content;
	char		*cmd_full_path;
	pid_t		pid;

	content = (t_cmd_cont *) node->content;
	cmd_full_path = get_cmd(content->cmd_name);
	if (!cmd_full_path)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		execve(cmd_full_path, content->args, g_env);
		perror(cmd_full_path);
	}
	else
	{
		waitpid(pid, NULL, 0);
		free(cmd_full_path);
	}
}
