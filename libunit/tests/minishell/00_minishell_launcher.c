/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_minishell_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:41:16 by graux             #+#    #+#             */
/*   Updated: 2023/02/23 13:47:21 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_tests.h"

t_status	minishell_launcher(void)
{
	size_t			routine_size;
	const t_utest	utests[] = {
	{.name = "basic_test", .func = &basic_test},
	{.name = "null_test", .func = &null_test},
	{.name = "segv_test", .func = &segv_test}
	};

	put_routine_title("Minishell global tests");
	routine_size = sizeof(utests) / sizeof(utests[0]);
	return (utest_run_routine(utests, routine_size));
}
