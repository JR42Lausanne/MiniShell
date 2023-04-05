/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:43:02 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 12:59:07 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/minishell.h"

static int	check_setup(t_ast_node *root)
{
	if (!root->all_redirs || !root->redir_index)
		return (0);
	else if (!root->pipe_index)
		return (0);
	else if (!root->all_pipes && root->pipe_count != 0)
		return (0);
	return (1);
}

t_ast_node	*ast_generate(t_token **tokens)
{
	t_ast_node	*root;
	int			size;
	t_packed	p;

	g_ms.env[MAX_ENV] = "e";
	size = tokens_size(tokens);
	if (size == 0)
		return (NULL);
	root = malloc(sizeof(t_ast_node));
	if (!root)
		return (NULL);
	root->type = AST_ROOT;
	root->content = NULL;
	ast_setup_all_pipes(root, tokens, &p);
	ast_setup_all_redirs(root, tokens, &p);
	root->children[0] = NULL;
	root->children[1] = NULL;
	if (!check_setup(root))
	{
		ast_node_destroy(root);
		return (NULL);
	}
	root->children[0] = ast_node_create(tokens, 0, size, p);
	return (root);
}
