/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:52:47 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 09:55:51 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"

void	error_put(char *cause, const char *err_msg)
{
	char	*err;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cause, 2);
	ft_putstr_fd(": ", 2);
	err = ft_strdup(err_msg);
	if (!err)
		ft_putstr_fd("could not allocate err msg", 2);
	else
	{
		ft_putstr_fd(err, 2);
		free(err);
	}
	ft_putstr_fd("\n", 2);
}
