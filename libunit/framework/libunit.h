/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:50:54 by graux             #+#    #+#             */
/*   Updated: 2023/02/06 15:46:45 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "status.h"
# include <stddef.h>

typedef struct s_utest
{
	char			*name;
	int				(*func)(void);
}		t_utest;

typedef enum e_test_sig
{
	T_OK = OK,
	T_KO,
	T_SEGV,
	T_BUSE,
	T_UNKOWN,
}			t_test_sig;

t_status	utest_run(const t_utest *utest);
t_status	utest_run_routine(const t_utest *utests, size_t routine_size);

t_test_sig	utest_parent_handle(const t_utest *utest);
void		utest_child_handle(const t_utest *utest);

// Helpers
void		put_routine_title(const char *title);
void		put_str(const char *str);
void		put_nbr(size_t nbr);

#endif
