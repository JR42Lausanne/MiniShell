/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:00:55 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/27 16:23:39 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_ast_node_type
{
	AST_ROOT = 0,
	AST_BUILTIN,
	AST_CMD,
	AST_COND_AND,
	AST_COND_OR,
	AST_IN_REDIR,
	AST_HEREDOC,
	AST_OUT_REDIR,
	AST_OUT_APPEND,
	AST_PIPE,
	AST_SPLIT,
	AST_TYPE_SIZE
}			t_ast_node_type;

const static int	g_ast_prio[AST_TYPE_SIZE] = {
[AST_ROOT] = 0,
[AST_BUILTIN] = ,
[AST_CMD] = ,
[AST_COND_AND] = ,
[AST_COND_OR] = ,
[AST_IN_REDIR] = 2,
[AST_HEREDOC] = 2,
[AST_OUT_REDIR] = 2,
[AST_OUT_APPEND] = 2,
[AST_PIPE] = 1
};

typedef struct s_ast_node
{
	t_ast_node_type		type;
	int					child_number;
	struct s_ast_node	*children;
}			t_ast_node;

#endif
