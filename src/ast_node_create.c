/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:47 by graux             #+#    #+#             */
/*   Updated: 2023/03/04 15:47:38 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

t_ast_node	*ast_node_create(t_token **tokens, int start, int size)
{
	t_ast_node	*node;
	int			type_pos;

	printf("AST node: start %d size %d\n", start, size);
	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	type_pos = ast_find_type(node, tokens, start, size);
	if (type_pos != -1)
	{
		node->children[0] = ast_node_create(tokens, start, type_pos - start);
		node->children[1] = ast_node_create(tokens, type_pos + 1,
				size - (type_pos - start) - 1);
	}
	else
	{
		node->type = AST_CMD;
		node->children[0] = NULL;
		node->children[1] = NULL;
	}
	return (node);
}
