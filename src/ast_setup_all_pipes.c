/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_setup_all_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:33:16 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 11:33:44 by graux            ###   ########.fr       */
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

void	ast_setup_all_pipes(t_ast_node *root, t_token **tokens, t_packed *p)
{
	int	i;

	root->pipe_index = malloc(sizeof(int));
	root->pipe_count = count_pipes(tokens);
	root->all_pipes = malloc(sizeof(int) * (2 * root->pipe_count));
	p->p = root->pipe_index;
	p->pipe_count = root->pipe_count;
	p->all_pipes = root->all_pipes;
	if (!root->all_pipes || !root->pipe_index)
		return ;
	i = -1;
	while (++i < root->pipe_count)
		pipe(root->all_pipes + (i * 2));
	*(root->pipe_index) = 0;
}
