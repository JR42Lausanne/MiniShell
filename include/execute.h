/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:30:14 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/30 13:59:04 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "ast.h"
# include <unistd.h>
# include <sys/types.h>

void	ast_execute(t_ast_node *node);
void	ast_execute_cmd(t_ast_node *node);
void	ast_execute_built(t_ast_node *node);
#endif
