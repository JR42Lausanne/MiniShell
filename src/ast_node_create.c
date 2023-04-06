/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:47 by graux             #+#    #+#             */
/*   Updated: 2023/04/06 14:29:57 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/libft.h"

static t_ast_node_type	find_exec_type(t_token **tokens, int start, int size)
{
	t_ast_node_type	type;
	int				i;

	i = start;
	type = AST_CMD;
	while (i < size + start && (tokens[i]->type != TOK_WORD
			|| is_redir(tokens[i])))
		i++;
	if (!tokens[i] || tokens[i]->type != TOK_WORD)
		return (AST_DO_NOTHING);
	if (!ft_strncmp(tokens[i]->content, "echo", ft_strlen("echo") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "cd", ft_strlen("cd") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "pwd", ft_strlen("pwd") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "export", ft_strlen("export") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "unset", ft_strlen("unset") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "env", ft_strlen("env") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(tokens[i]->content, "exit", ft_strlen("exit") + 1))
		type = AST_BUILTIN;
	return (type);
}

static void	ast_node_gen_content(t_ast_node *node, t_token **tokens, int start,
		int size)
{
	if (node->type != AST_INVALID)
		node->type = find_exec_type(tokens, start, size);
	if (node->type == AST_CMD)
		ast_node_gen_cmd(node, tokens, start, size);
	else if (node->type == AST_BUILTIN)
		ast_node_gen_builtin(node, tokens, start, size);
	node->children[0] = NULL;
	node->children[1] = NULL;
}

static void	setup_node(t_ast_node *node, t_packed *p)
{
	node->pid = -1;
	node->fd_in = STDIN_FILENO;
	node->fd_out = STDOUT_FILENO;
	node->redir_fd_in = -1;
	node->redir_fd_out = -1;
	node->pipe_index = p->p;
	node->pipe_count = p->pipe_count;
	node->all_pipes = p->all_pipes;
	node->all_redirs = p->all_redirs;
	node->redir_index = p->redir_index;
	node->exit_status = -1;
}

t_ast_node	*ast_node_create(t_token **tokens, int start, int size, t_packed p)
{
	t_ast_node	*node;
	int			type_pos;

	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	type_pos = ast_find_type(node, tokens, start, size);
	setup_node(node, &p);
	if (type_pos != -1)
	{
		node->children[0] = ast_node_create(tokens, start, type_pos - start, p);
		node->children[1] = ast_node_create(tokens, type_pos + 1,
				size - (type_pos - start) - 1, p);
	}
	else
	{
		if (!ast_node_gen_redir(node, tokens, start, size))
			node->type = AST_INVALID;
		ast_node_gen_content(node, tokens, start, size);
	}
	return (node);
}
