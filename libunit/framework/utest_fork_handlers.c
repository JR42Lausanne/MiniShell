/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest_fork_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:08:39 by graux             #+#    #+#             */
/*   Updated: 2023/02/06 15:43:33 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

static t_test_sig	decode_term_sig(int term_sig)
{
	if (term_sig == SIGSEGV)
		return (T_SEGV);
	else if (term_sig == SIGBUS)
		return (T_BUSE);
	else
		return (T_UNKOWN);
}

t_test_sig	utest_parent_handle(const t_utest *utest)
{
	t_test_sig	res;
	int			child_status;

	wait(&child_status);
	if (WIFEXITED(child_status))
		res = WEXITSTATUS(child_status);
	else if (WIFSIGNALED(child_status))
		res = decode_term_sig(WTERMSIG(child_status));
	return (res);
}

void	utest_child_handle(const t_utest *utest)
{
	t_status	status;

	status = utest->func();
	exit(status);
}
