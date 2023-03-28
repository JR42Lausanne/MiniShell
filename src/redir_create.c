/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:47 by graux             #+#    #+#             */
/*   Updated: 2023/03/28 14:51:41 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

int	redir_create(t_token *tok)
{
	if (tok->type == TOK_REDIR_IN)
		return (redir_create_i(tok));
	else if (tok->type == TOK_REDIR_OUT)
		return (redir_create_o(tok));
	else if (tok->type == TOK_REDIR_APP)
		return (redir_create_a(tok));
	return (-4);
}
