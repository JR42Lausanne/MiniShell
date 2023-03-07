/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_gen_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:42:23 by graux             #+#    #+#             */
/*   Updated: 2023/03/07 15:25:02 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"

char	**ast_gen_args(t_token **tokens, int start, int size)
{
	char	**args;
	int		pos;
	int		i;

	args = malloc((size + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	pos = ast_find_name_pos(tokens, start, size);
	while (pos != -1)
	{
		args[i++] = ft_strdup(tokens[pos]->content);
		pos = ast_find_name_pos(tokens, pos + 1, size - (pos - start) - 1);
	}
	args[i] = NULL;
	return (args);
}
