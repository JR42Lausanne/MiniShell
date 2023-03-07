/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_find_name_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:15:17 by graux             #+#    #+#             */
/*   Updated: 2023/03/07 10:03:41 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

int	ast_find_name_pos(t_token **tokens, int start, int size)
{
	int		i;

	i = 0;
	//TODO check correct names
	while (i < size)
	{
		if (i == 0 && tokens[i + start]->type == TOK_WORD)
			return (i + start);
		else if (tokens[i + start]->type == TOK_WORD
			&& tokens[i - 1 + start]->type < TOK_REDIR_IN
			&& tokens[i - 1 + start]->type > TOK_HEREDOC)
		{
			return (i + start);
		}
		i++;
	}
	return (-1);
}
