/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:25:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/17 11:48:44 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ENV 1000

extern char	**g_env;

char	*ms_getenv(char *name);
char	*ms_getenv_cont(char *name);
int		ms_envsetup(char **envp);

void	signal_handler(int sig);
int		signal_setup(void);

#endif
