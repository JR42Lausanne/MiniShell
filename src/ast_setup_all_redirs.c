/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_setup_all_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:48 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 11:31:49 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

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
		if (tokens[i]->type == TOK_HEREDOC)
			count++;
	}
	return (count);
}

void	ast_setup_all_redirs(t_ast_node *root, t_token **tokens, t_packed *p)
{
	int	i;
	int	size;

	size = count_redirs(tokens) + 1;
	root->all_redirs = malloc(sizeof(int) * size);
	root->redir_index = malloc(sizeof(int));
	p->all_redirs = root->all_redirs;
	p->redir_index = root->redir_index;
	if (!root->all_redirs || !root->redir_index)
		return ;
	i = -1;
	while (++i < size)
		root->all_redirs[i] = -2;
	*(root->redir_index) = 0;
}
