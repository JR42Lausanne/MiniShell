/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:43:02 by graux             #+#    #+#             */
/*   Updated: 2023/03/22 16:38:59 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static int	count_pipes(t_token **tokens)
{
	int	i;
	int	size;
	int	count;

	size = tokens_size(tokens);
	i = -1;
	count = 0;
	while (++i < size)
	{
		if (tokens[i]->type == TOK_PIPE)
			count++;
	}
	return (count);
}

static void	setup_all_pipes(t_ast_node *root, t_token **tokens)
{
	int	i;

	root->pipe_index = malloc(sizeof(int));
	root->pipe_count = count_pipes(tokens);
	root->all_pipes = malloc(sizeof(int) * (2 * root->pipe_count));
	if (!root->all_pipes)
		return ;
	i = -1;
	while (++i < root->pipe_count)
		pipe(root->all_pipes + (i * 2));
}

static int	count_redirs(t_token **tokens)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tokens[++i])
	{
		if (is_redir(tokens[i]))
			count++;
	}
	return (count);
}

static void	setup_all_redirs(t_ast_node *root, t_token **tokens)
{
	int	i;
	int	size;

	size = count_redirs(tokens) + 1;
	root->all_redirs = malloc(sizeof(int) * size);
	if (!root->all_redirs)
		return ;
	i = -1;
	while (++i < size)
		root->all_redirs[i] = -2;
	root->redir_index = malloc(sizeof(int));
	if (!root->all_redirs)
		return ; //TODO better protection
	*(root->redir_index) = 0;
}

t_ast_node	*ast_generate(t_token **tokens)
{
	t_ast_node	*root;
	int			size;
	t_packed	p;

	size = tokens_size(tokens);
	if (size == 0)
		return (NULL);
	root = malloc(sizeof(t_ast_node));
	if (!root)
		return (NULL);
	root->type = AST_ROOT;
	root->content = NULL;
	setup_all_pipes(root, tokens);
	setup_all_redirs(root, tokens);
	p.pipe_count = root->pipe_count;
	p.p = root->pipe_index;
	p.all_pipes = root->all_pipes;
	p.all_redirs = root->all_redirs;
	p.redir_index = root->redir_index;
	if (!root->pipe_index)
		return (NULL);
	*(root->pipe_index) = 0;
	root->children[1] = NULL;
	root->children[0] = ast_node_create(tokens, 0, size, p);
	return (root);
}
