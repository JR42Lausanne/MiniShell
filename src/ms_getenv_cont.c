/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:45:25 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/06 17:10:57 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

char	*ms_getenv_cont(char *name)
{
	int		i;
	char	*match;

	i = 0;
	while (g_env[i] != 0)
	{
		match = ft_strnstr(g_env[i], name, ft_strlen(g_env[i]));
		if (match)
		{
			if (match == g_env[i])
				return (ft_strdup(g_env[i] + (ft_strlen(name)) + 1));
		}
		i++;
	}
	return (NULL);
}
