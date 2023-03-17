/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_find_name_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:15:17 by graux             #+#    #+#             */
/*   Updated: 2023/03/17 16:04:00 by graux            ###   ########.fr       */
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
			&& !is_redir(tokens[i + start]))
		{
			return (i + start);
		}
		i++;
	}
	return (-1);
}
