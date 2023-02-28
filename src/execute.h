/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:30:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/28 14:41:35 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

typedef struct	s_exe
{
	char	*path;
	char	*cmd_path;
	char	*cmd;
	char	*cmd_arg;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;	
}				t_exe;

char	*check_path(char	*env);
void	ast_execute(t_ast *ast);

#endif
