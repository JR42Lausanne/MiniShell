/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:45:25 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/28 16:22:16 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

char	*ms_getenv_cont(char *name)
{
	int		i;
	char	*match;

	i = 0;
	while (g_ms.env[i] != 0)
	{
		match = ft_strnstr(g_ms.env[i], name, ft_strlen(g_ms.env[i]));
		if (match)
		{
			if (match == g_ms.env[i] && match[ft_strlen(name)] == '=')
				return (ft_strdup(g_ms.env[i] + (ft_strlen(name)) + 1));
		}
		i++;
	}
	return (NULL);
}
