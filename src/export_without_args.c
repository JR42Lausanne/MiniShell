/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_without_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:24:56 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/29 16:35:02 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtins.h"
#include "../include/libft.h"

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
