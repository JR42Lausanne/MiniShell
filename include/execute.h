/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:30:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/28 18:00:57 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "ast.h"
# include <unistd.h>
# include <sys/types.h>

typedef struct	s_exe
{
	char	*path;
	char	**path_bin;
	char	*cmd;
	char	**cmd_opt;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;	
}				t_exe;

//void	ast_run(t_ast_node *root); MAYBE
void	ast_execute(t_ast_node *node);
void	ast_execute_cmd(t_ast_node *node);
void	ast_execute_built(t_ast_node *node);
#endif
