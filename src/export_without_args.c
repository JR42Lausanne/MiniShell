/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_without_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:34:30 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 14:35:21 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/minishell.h"
#include <stdio.h>

void	export_without_args(void)
{
	int	i;

	i = -1;
	while (++i < MAX_ENV && g_ms.env[i])
	{
		printf("declare -x ");
		printf("%.*s", var_name_len(g_ms.env[i]), g_ms.env[i]);
		printf("=\"%s\"\n", g_ms.env[i] + var_name_len(g_ms.env[i]) + 1);
	}
}
