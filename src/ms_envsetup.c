/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envsetup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:44:53 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/28 16:20:42 by graux            ###   ########.fr       */
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

	g_ms.env = malloc(sizeof(char *) * (MAX_ENV + 1));
	if (!g_ms.env)
		return (1);
	i = 0;
	while (i < MAX_ENV && envp[i])
	{
		g_ms.env[i] = ft_strdup(envp[i]);
		i++;
	}
	if (envp[i])
		return (1); //TODO free
	while (i < MAX_ENV)
		g_ms.env[i++] = NULL;
	increase_shlvl();
	return (0);
}
