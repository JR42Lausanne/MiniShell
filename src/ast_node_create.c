/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:47 by graux             #+#    #+#             */
/*   Updated: 2023/03/16 13:38:06 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/libft.h"

static t_ast_node_type	find_exec_type(t_token **tokens, int start, int size)
{
	t_ast_node_type	type;
	int				i;

	i = start;
	//TODO skip redirections correctly and check if i = size + start
	while (i < size + start && tokens[i]->type != TOK_WORD)
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

t_ast_node	*ast_node_create(t_token **tokens, int start, int size, t_packed p)
{
	t_ast_node	*node;
	int			type_pos;

	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	type_pos = ast_find_type(node, tokens, start, size);
	node->pid = -1;
	node->fd_in = STDIN_FILENO;
	node->fd_out = STDOUT_FILENO;
	node->pipe_index = p.p;
	node->pipe_count = p.pipe_count;
	node->all_pipes = p.all_pipes;
	if (type_pos != -1)
	{
		node->children[0] = ast_node_create(tokens, start, type_pos - start, p);
		node->children[1] = ast_node_create(tokens, type_pos + 1,
				size - (type_pos - start) - 1, p);
	}
	else
	{
		ast_node_gen_content(node, tokens, start, size);
		//TODO after that populate redirs
	}
	return (node);
}
