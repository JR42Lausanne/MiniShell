/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:17:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/02 14:07:42 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/minishell.h"
#include "../include/libft.h"

int	builtin_unset(char	**args)
{
	int	i;

	if (args && !args[1])
		return (1);
	i = 0;
	while (i < MAX_ENV)
	{
		if (ft_strnstr(g_env[i], args[1], ft_strlen(args[1])))
		{	
			free(g_env[i]);
			g_env[i] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}	
