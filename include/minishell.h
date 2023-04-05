/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:25:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/05 12:11:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>

# define MAX_ENV 1000
# define PROMPT_SIZE 50

# define GREEN "\033[38;5;10m"
# define RESET "\033[0m"

typedef struct s_ms
{
	char					**env;
	volatile sig_atomic_t	status;
}			t_ms;

extern t_ms	g_ms;

char	*ms_getenv(char *name);
char	*ms_getenv_cont(char *name);
int		ms_envsetup(char **envp);

void	signal_handler(int sig);
int		signal_setup(void);

void	error_put(char *cause, const char *err_msg);
int		free_args(char **args);

#endif
