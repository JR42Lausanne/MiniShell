/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:25:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/06 16:55:47 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ENV 1000

extern char	*g_env[MAX_ENV];

char	*ms_getenv(char *name);
char	*ms_getenv_cont(char *name);
int		ms_envsetup(char **envp);

#endif
