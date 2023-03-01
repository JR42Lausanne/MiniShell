/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:38 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/01 11:04:26 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

void	ast_execute_built(t_ast *node)
{

void	builtin_echo(int option, char *text);
void	builtin_cd(char *path);
void	builtin_pwd(void);
void	builtin_export(char *var, char *value);
//TODO correct arguments
void	builtin_unset(void);
void	builtin_env(void);
void	builtin_exit(void);



	check_type_of_built


}
