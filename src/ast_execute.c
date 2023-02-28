/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/28 14:45:35 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <stdlib.h>

void	ast_execute(t_ast *ast)
{
	t_exe	*exe;

	exe->path = getenv("PATH");
	exe->cmd_path = check_path(exe->path);
	
}
