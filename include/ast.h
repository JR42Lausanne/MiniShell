/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:00:55 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/04 11:12:43 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "tokenizer.h"

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
	AST_TYPE_SIZE
}			t_ast_node_type;

typedef struct s_cmd_cont
{
	char	*cmd_name;
	char	**args;
	int		pipe_fd[2];
}			t_cmd_cont;

typedef struct s_builtin_cont
{
	int		(*func_pointer)(char **);
	char	**args;
}			t_builtin_cont;

typedef struct s_ast_node
{
	t_ast_node_type		type;
	int					child_number;
	void				*content;
	struct s_ast_node	*children[2];
}			t_ast_node;

t_ast_node		*ast_node_create(t_token **tokens, int start, int size);
int				ast_find_type(t_ast_node *node, t_token **tokens, int start,
					int size);

t_ast_node		*ast_generate(t_token **tokens);
void			ast_print(t_ast_node *root, int depth);

#endif
