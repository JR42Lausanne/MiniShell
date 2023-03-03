/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:47 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 18:36:57 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

t_ast_node	*ast_node_create(t_token **tokens, int start, int size)
{
	t_ast_node	*node;

	printf("AST node: start %d size %d\n", start, size);
	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->type = ast_find_type(tokens, start, size);
	return (node);
}
