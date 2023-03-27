/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:25:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/26 16:02:34 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ENV 1000
# define PROMPT_SIZE 50

# define GREEN "\033[38;5;10m"
# define RESET "\033[0m"

extern char	**g_env;

char	*ms_getenv(char *name);
char	*ms_getenv_cont(char *name);
int		ms_envsetup(char **envp);

void	signal_handler(int sig);
int		signal_setup(void);
// Error handling
void	error_put(char *cause, const char *err_msg);

#endif
