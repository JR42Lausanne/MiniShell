/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:44 by graux             #+#    #+#             */
/*   Updated: 2023/03/07 18:43:35 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

int	ast_node_redirect(t_redir **redirs, t_redir pipe_redir)
{
	dup2(pipe_redir.fd_new, pipe_redir.fd_old);
	if (!redirs)
		return (0);
	return (0);
}
