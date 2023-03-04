/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_gen_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:03:39 by graux             #+#    #+#             */
/*   Updated: 2023/03/04 18:19:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/libft.h"

static char	*find_name(t_token **tokens, int start, int size)
{
	char	*name;
	int		i;

	i = start;
	while (i < size - start)
	{
		if (i == start && tokens[i]->type == TOK_WORD)
		{
			name = tokens[i]->content;
			break ;
		}
		else if (tokens[i]->type == TOK_WORD
			&& tokens[i - 1]->type < TOK_REDIR_IN
			&& tokens[i - 1]->type > TOK_HEREDOC)
		{
			name = tokens[i]->content;
			break ;
		}
	}
	return (ft_strdup(name));
}

void	ast_node_gen_cmd(t_ast_node *node, t_token **tokens, int start,
		int size)
{
	t_cmd_cont	*content;

	content = malloc(sizeof(t_cmd_cont));
	if (!content)
		return ; //TODO protection
	content->cmd_name = find_name(tokens, start, size);
	content->args = NULL; //TODO change that to the real thing
	node->content = content;
}
