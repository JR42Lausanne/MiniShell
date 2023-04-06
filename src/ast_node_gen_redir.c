/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_gen_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:18 by graux             #+#    #+#             */
/*   Updated: 2023/04/06 14:10:02 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

static int	handle_redir_in(t_token **tokens, t_ast_node *node, int i,
		int start)
{
	node->redir_fd_in = redir_create(tokens[i + start]);
	node->all_redirs[(*(node->redir_index))++] = node->redir_fd_in;
	return (node->redir_fd_in != -1);
}

static int	handle_redir_out(t_token **tokens, t_ast_node *node, int i,
		int start)
{
	node->redir_fd_out = redir_create(tokens[i + start]);
	node->all_redirs[(*(node->redir_index))++] = node->redir_fd_out;
	return (node->redir_fd_out != -1);
}

static int	handle_redir_h(t_token **tokens, t_ast_node *node, int i,
		int start)
{
	t_fds	fds;

	fds = redir_create_h(tokens[i + start]);
	node->redir_fd_in = fds.in;
	node->all_redirs[(*(node->redir_index))++] = fds.in;
	node->all_redirs[(*(node->redir_index))++] = fds.out;
	return (fds.in != -1 && fds.out != -1);
}

int	ast_node_gen_redir(t_ast_node *node, t_token **tokens, int start, int size)
{
	int			i;
	static int	status;

	if (start == 0)
		status = 1;
	if (!status)
		return (1);
	i = start - 1;
	while (++i < size)
	{
		if (tokens[i + start]->type == TOK_REDIR_IN)
			status = handle_redir_in(tokens, node, i, start);
		else if (tokens[i + start]->type == TOK_HEREDOC)
			status = handle_redir_h(tokens, node, i, start);
		else if (tokens[i + start]->type == TOK_REDIR_OUT
			|| tokens[i]->type == TOK_REDIR_APP)
			status = handle_redir_out(tokens, node, i, start);
		if (!status)
			break ;
	}
	return (status);
}
