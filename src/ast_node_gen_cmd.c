/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_gen_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:03:39 by graux             #+#    #+#             */
/*   Updated: 2023/03/07 11:35:19 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/libft.h"

void	ast_node_gen_cmd(t_ast_node *node, t_token **tokens, int start,
		int size)
{
	t_cmd_cont	*content;
	int			pos;

	content = malloc(sizeof(t_cmd_cont));
	if (!content)
		return ;
	pos = ast_find_name_pos(tokens, start, size);
	if (pos != -1)
		content->cmd_name = ft_strdup(tokens[pos]->content);
	content->args = ast_gen_args(tokens, start, size);
	node->content = content;
}
