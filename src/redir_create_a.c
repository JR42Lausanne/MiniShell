/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_create_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:32:56 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 17:44:31 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include <fcntl.h>

int	redir_create_a(t_token *tok)
{
	int	fd;

	fd = open(tok->content, O_WRONLY | O_CREAT | O_APPEND);
	if (fd == -1)
		perror(tok->content);
	return (fd);
}
