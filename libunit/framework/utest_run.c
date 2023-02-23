/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:50:39 by graux             #+#    #+#             */
/*   Updated: 2023/02/06 15:45:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "color.h"
#include <stdlib.h>
#include <unistd.h>

static void	print_routine_recap(size_t passed, size_t total)
{
	put_str("\n--------------- ");
	if (passed == total)
		put_str(GREEN"OK "RESET"-> ");
	else
		put_str(RED"FAIL "RESET"-> ");
	put_nbr(passed);
	put_str("/");
	put_nbr(total);
	put_str(" ---------------\n");
}

static void	print_status(t_test_sig status)
{
	put_str("[");
	if (status == T_OK)
		put_str(GREEN"OK"RESET);
	else if (status == 255)
		put_str(RED"KO"RESET);
	else if (status == T_SEGV)
		put_str(RED"SEGV"RESET);
	else if (status == T_BUSE)
		put_str(RED"BUSE"RESET);
	else
		put_str(YELLOW"UNKOWN SIG FROM TEST"RESET);
	put_str("]");
}

static void	print_test_recap(const t_utest *utest, t_test_sig status)
{
	put_str(" > ");
	put_str(utest->name);
	put_str(": ");
	print_status(status);
	put_str("\n");
}

t_status	utest_run(const t_utest *utest)
{
	int			pid;
	t_test_sig	status;

	pid = fork();
	if (pid == 0)
		utest_child_handle(utest);
	else
		status = utest_parent_handle(utest);
	print_test_recap(utest, status);
	if (status == T_OK)
		return (OK);
	else
		return (FAIL);
}

t_status	utest_run_routine(const t_utest *utests, size_t routine_size)
{
	size_t		i;
	size_t		passed_tests;
	t_status	status;

	status = OK;
	i = 0;
	passed_tests = 0;
	while (i < routine_size)
	{
		if (utest_run(&utests[i]) != OK)
			status = FAIL;
		else
			passed_tests++;
		i++;
	}
	print_routine_recap(passed_tests, routine_size);
	return (status);
}
