/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envsetup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:44:53 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/16 12:48:06 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

char	*g_env[MAX_ENV + 1];

int	ms_envsetup(char **envp)
{
	int	i;

	i = 0;
	while (i < MAX_ENV && envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	if (!envp[i])
		return (1); //TODO free
	while (i < MAX_ENV)
		g_env[i++] = NULL;
	return (0);
}
