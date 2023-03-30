/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:12:14 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 15:02:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <dirent.h>

static int	contain_wild(t_token **tokens, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tokens[i]->type == TOK_WILDCARD)
			return (1);
	}
	return (0);
}

t_token	**expand_wildcards(t_token **tokens)
{
	t_token	**expanded;
	t_token	**tmp;
	int		size;

	expanded = tokens;
	size = tokens_size(tokens);
	while (contain_wild(expanded, size))
	{
		tmp = expanded;
		expanded = expand_one(tmp, size);
		if (tmp != expanded)
			free(tmp);
		size = tokens_size(expanded);
	}
	return (expanded);
}
