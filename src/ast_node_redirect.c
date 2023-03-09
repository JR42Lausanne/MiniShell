/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:14:44 by graux             #+#    #+#             */
/*   Updated: 2023/03/09 11:25:28 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

int	ast_node_redirect(t_redir **redirs, t_redir pipe_redir)
{
	dup2(pipe_redir.fd_new, pipe_redir.fd_old);
	close(pipe_redir.fd_pipe_other);
	if (!redirs)
		return (0);
	return (0);
}
