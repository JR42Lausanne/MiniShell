/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:47 by graux             #+#    #+#             */
/*   Updated: 2023/03/09 14:27:34 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/libft.h"

static t_ast_node_type	find_exec_type(t_token **tokens, int start, int size)
{
	t_ast_node_type	type;
	int				i;

	i = start;
	//TODO skip redirections correctly
	while (tokens[i]->type != TOK_WORD && i < size - start)
		i++;
	if (!ft_strncmp(tokens[i]->content, "echo", ft_strlen("echo")))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "cd", ft_strlen("cd")))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "pwd", ft_strlen("pwd")))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "export", ft_strlen("export")))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "unset", ft_strlen("unset")))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "env", ft_strlen("env")))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "exit", ft_strlen("exit")))
		type = AST_BUILTIN;
	else
		type = AST_CMD;
	return (type);
}

static void	ast_node_gen_content(t_ast_node *node, t_token **tokens, int start,
		int size)
{
	node->type = find_exec_type(tokens, start, size);
	//TODO populate redirections
	if (node->type == AST_CMD)
		ast_node_gen_cmd(node, tokens, start, size);
	else
		ast_node_gen_builtin(node, tokens, start, size);
	node->children[0] = NULL;
	node->children[1] = NULL;
}

t_ast_node	*ast_node_create(t_token **tokens, int start, int size)
{
	t_ast_node	*node;
	int			type_pos;

	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	type_pos = ast_find_type(node, tokens, start, size);
	node->redirs = NULL;
	node->pid = -1;
	node->pipe_redir_out.fd_old = -1;
	node->pipe_redir_out.fd_new = -1;
	node->pipe_redir_out.fd_pipe_other = -1;
	node->pipe_redir_in.fd_old = -1;
	node->pipe_redir_in.fd_new = -1;
	node->pipe_redir_in.fd_pipe_other = -1;
	node->pipe_in[0] = -1;
	node->pipe_in[1] = -1;
	node->pipe_out[0] = -1;
	node->pipe_out[1] = -1;
	if (type_pos != -1)
	{
		node->children[0] = ast_node_create(tokens, start, type_pos - start);
		node->children[1] = ast_node_create(tokens, type_pos + 1,
				size - (type_pos - start) - 1);
	}
	else
	{
		ast_node_gen_content(node, tokens, start, size);
		//TODO after that populate redirs
	}
	return (node);
}
