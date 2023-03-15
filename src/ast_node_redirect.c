/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:44 by graux             #+#    #+#             */
/*   Updated: 2023/03/15 17:13:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_close_all_pipes(t_ast_node *node)
{
	int	i;

	i = -1;
	while (++i < node->pipe_count * 2)
		close(node->all_pipes[i]);
}

int	ast_node_redirect(t_ast_node *node)
{
	if (!node)
		return (1);
	dup2(node->fd_in, STDIN_FILENO);
	dup2(node->fd_out, STDOUT_FILENO);
	ast_close_all_pipes(node);
	return (0);
}
