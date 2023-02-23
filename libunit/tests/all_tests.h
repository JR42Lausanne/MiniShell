/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:44:35 by graux             #+#    #+#             */
/*   Updated: 2023/02/23 13:49:46 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_TESTS_H
# define ALL_TESTS_H

# include "../framework/libunit.h"

// Minishell
t_status	minishell_launcher(void);
t_status	basic_test(void);
t_status	null_test(void);
t_status	segv_test(void);

#endif
