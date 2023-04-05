/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_create_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:30:04 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 16:31:08 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include <fcntl.h>

int	redir_create_i(t_token *tok)
{
	int	fd;

	fd = open(tok->content, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(tok->content);
	}
	return (fd);
}
