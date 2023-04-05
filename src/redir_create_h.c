/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_create_h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:32:26 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 16:33:33 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static int	read_hearedoc(int pipe_fd[2], t_token *tok)
{
	char	*stop;
	char	*curr_line;

	stop = tok->content;
	curr_line = readline("> ");
	if (!curr_line)
		return (0);
	while (curr_line && ft_strncmp(curr_line, stop,
			max(ft_strlen(curr_line), ft_strlen(stop))) != 0)
	{
		write(pipe_fd[1], curr_line, ft_strlen(curr_line));
		write(pipe_fd[1], "\n", 1);
		free(curr_line);
		curr_line = readline("> ");
	}
	free(curr_line);
	return (1);
}

t_fds	redir_create_h(t_token *tok)
{
	t_fds	fds;
	int		pipe_fd[2];

	fds.in = -1;
	fds.out = -1;
	if (pipe(pipe_fd) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(tok->content);
		return (fds);
	}
	if (read_hearedoc(pipe_fd, tok))
	{
		fds.in = pipe_fd[0];
		fds.out = pipe_fd[1];
	}
	return (fds);
}
