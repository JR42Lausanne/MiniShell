/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:00:55 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/09 11:22:28 by graux            ###   ########.fr       */
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
}			t_cmd_cont;

typedef struct s_builtin_cont
{
	int		(*func_pointer)(char **);
	char	**args;
}			t_builtin_cont;

typedef struct s_redir
{
	int	fd_old;
	int	fd_new;
	int	fd_pipe_other;
}			t_redir;

typedef struct s_ast_node
{
	t_ast_node_type		type;
	void				*content;
	t_redir				**redirs;
	t_redir				pipe_redir;
	pid_t				pid;
	struct s_ast_node	*children[2];
}			t_ast_node;

t_ast_node		*ast_node_create(t_token **tokens, int start, int size);
void			ast_node_gen_cmd(t_ast_node *node, t_token **tokens, int start,
					int size);
void			ast_node_gen_builtin(t_ast_node *node, t_token **tokens,
					int start, int size);
int				ast_find_type(t_ast_node *node, t_token **tokens, int start,
					int size);
int				ast_find_name_pos(t_token **tokens, int start, int size);
char			**ast_gen_args(t_token **tokens, int start, int size);

// for a value in redirs_fd [0] -> is the new fd and [1] the old
int				ast_node_redirect(t_redir **redirs, t_redir pipe_redir);

t_ast_node		*ast_generate(t_token **tokens);
void			ast_print(t_ast_node *root, int depth);

#endif
