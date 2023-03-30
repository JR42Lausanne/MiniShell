/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:51:50 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 14:52:12 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

char	*get_full_cmd(char *directory, char *cmd_name)
{
	char	*tmp;
	char	*command;

	tmp = ft_strjoin(directory, "/");
	if (!tmp)
		return (NULL);
	command = ft_strjoin(tmp, cmd_name);
	free(tmp);
	return (command);
}
