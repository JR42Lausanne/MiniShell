/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:22:09 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 22:07:44 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

char	*ms_getenv(char	*name)
{
	int		i;
	char	*copy;
	char	*match;

	i = 0;
	while (g_env[i] != 0)
	{
		match = ft_strnstr(g_env[i], name, ft_strlen(g_env[i]));
		if (match)
		{
			if (match == g_env[i])
				copy = ft_strdup(g_env[i]);
		}
		i++;
	}
	return (copy);
}
