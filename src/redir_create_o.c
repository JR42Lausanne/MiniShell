/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_create_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:31:41 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 11:02:03 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include <fcntl.h>

int	redir_create_o(t_token *tok)
{
	int	fd;

	fd = open(tok->content, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		perror(tok->content);
	return (fd);
}
