/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envsetup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:44:53 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/17 12:38:15 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

char	**g_env;

int	ms_envsetup(char **envp)
{
	int	i;

	g_env = malloc(sizeof(char *) * (MAX_ENV + 1));
	if (!g_env)
		return (1);
	i = 0;
	while (i < MAX_ENV && envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	if (envp[i])
		return (1); //TODO free
	while (i < MAX_ENV)
		g_env[i++] = NULL;
	return (0);
}
