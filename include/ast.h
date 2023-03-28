/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:00:55 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/28 18:02:29 by graux            ###   ########.fr       */
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

typedef struct s_ast_node
{
	t_ast_node_type		type;
	void				*content;
	int					fd_in;
	int					fd_out;
	int					redir_fd_in;
	int					redir_fd_out;
	int					pipe_count;
	int					*pipe_index;
	int					*all_pipes;
	int					*all_redirs;
	int					*redir_index;
	int					exit_status;
	pid_t				pid;
	struct s_ast_node	*children[2];
}			t_ast_node;

typedef struct s_packed
{
	int	pipe_count;
	int	*p;
	int	*all_pipes;
	int	*all_redirs;
	int	*redir_index;
}			t_packed;

typedef struct s_fds
{
	int	in;
	int	out;
}			t_fds;

t_ast_node		*ast_node_create(t_token **tokens, int start, int size,
					t_packed packed);
void			ast_node_destroy(t_ast_node *node);
void			ast_node_gen_cmd(t_ast_node *node, t_token **tokens, int start,
					int size);
void			ast_node_gen_builtin(t_ast_node *node, t_token **tokens,
					int start, int size);
int				ast_find_type(t_ast_node *node, t_token **tokens, int start,
					int size);
int				ast_find_name_pos(t_token **tokens, int start, int size);
char			**ast_gen_args(t_token **tokens, int start, int size);

// for a value in redirs_fd [0] -> is the new fd and [1] the old
int				ast_node_redirect(t_ast_node *node);
int				redir_create_i(t_token *tok);
int				redir_create_o(t_token *tok);
int				redir_create_a(t_token *tok);
t_fds			redir_create_h(t_token *tok);
int				redir_create(t_token *tok);

t_ast_node		*ast_generate(t_token **tokens);
void			ast_print(t_ast_node *root, int depth);
int				ast_wait(t_ast_node *node);
void			ast_close_all_pipes(t_ast_node *node);
void			ast_close_all_redirs(t_ast_node *node);

#endif
