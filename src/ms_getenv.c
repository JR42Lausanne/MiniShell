/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:22:09 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 20:10:52 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

char	*ms_getenv(char	*name)
{
	int		i;
	char	**env;
	char	*copy;
	char	*match;

	env = g_env;
	i = 0;
	while (env[i] != 0)
	{
		match = ft_strnstr(env[i], name, ft_strlen(env[i]));
		if (match)
		{
			if (match == env[i])
				copy = ft_strdup(env[i]);
		}
		i++;
	}
	return (copy);
}
