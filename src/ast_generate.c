/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:43:02 by graux             #+#    #+#             */
/*   Updated: 2023/03/07 10:09:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

t_ast_node	*ast_generate(t_token **tokens)
{
	t_ast_node	*root;
	int			size;

	size = tokens_size(tokens);
	if (size == 0)
		return (NULL);
	root = malloc(sizeof(t_ast_node));
	if (!root)
		return (NULL);
	root->type = AST_ROOT;
	root->content = NULL;
	root->children[1] = NULL;
	root->children[0] = ast_node_create(tokens, 0, size);
	return (root);
}
