/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envsetup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:44:53 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/05 12:55:45 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"
#include "../include/builtins.h"

t_ms	g_ms;

static void	increase_shlvl(void)
{
	char	*shlvl;
	char	*args[3];
	char	*temp;
	int		i_shlvl;

	shlvl = ms_getenv_cont("SHLVL");
	args[0] = "export";
	args[2] = NULL;
	if (!shlvl)
		args[1] = ft_strjoin("SHLVL=", "1");
	else
	{
		i_shlvl = ft_atoi(shlvl) + 1;
		free(shlvl);
		temp = ft_itoa(i_shlvl);
		args[1] = ft_strjoin("SHLVL=", temp);
		free(temp);
	}
	builtin_export(args);
	free(args[1]);
}

int	ms_envsetup(char **envp)
{
	int	i;

	if (signal_setup() == -1)
		return (0);
	g_ms.env = ft_calloc((MAX_ENV + 2), sizeof(char *));
	if (!g_ms.env)
		return (0);
	i = -1;
	while (++i < MAX_ENV && envp[i])
	{
		g_ms.env[i] = ft_strdup(envp[i]);
		if (!g_ms.env[i])
		{
			free_args(g_ms.env);
			return (0);
		}
	}
	if (envp[i])
	{
		free_args(g_ms.env);
		return (0);
	}
	g_ms.status = 0;
	increase_shlvl();
	return (1);
}
