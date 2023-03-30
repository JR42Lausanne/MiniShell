/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:31:35 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 09:19:57 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h>

static void	handle_sigint(void)
{
	if (*g_ms.env[MAX_ENV] == 'p')
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (*g_ms.env[MAX_ENV] == 'e')
	{
		printf("\n");
		g_ms.status = 130;
	}
}

static void	handle_sigquit(void)
{
	rl_on_new_line();
	rl_redisplay();
}

int	signal_setup(void)
{
	struct sigaction	sig;
	struct termios		tp;

	//TODO setup ECHOCTL in termios
	//printf("IN SIG SETUP\n");
	sig.sa_handler = &signal_handler;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
	if (tcgetattr(STDIN_FILENO, &tp) == -1)
		return (-1);
	//printf("first test\n");
	tp.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp) == -1)
		return (-1);
	//printf("second test\n");
	return (0);
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
		handle_sigint();
	else if (sig == SIGQUIT)
		handle_sigquit();
}
