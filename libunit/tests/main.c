/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:45:32 by graux             #+#    #+#             */
/*   Updated: 2023/02/23 13:56:03 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_tests.h"

int	main(int argc, char *argv[])
{
	t_status	status;

	status = OK;
	status |= minishell_launcher();
	return (-status);
}
