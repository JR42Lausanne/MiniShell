/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregate_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:22:26 by graux             #+#    #+#             */
/*   Updated: 2023/03/16 15:25:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static void	agreg_two(t_token **tokens, int pos)
{
	char	*temp;

	temp = tokens[pos]->content;
	tokens[pos]->content = ft_strjoin(temp, tokens[pos + 1]->content);
	free(temp);
	token_destroy(tokens[pos + 1]);
	while (tokens[++pos])
		tokens[pos] = tokens[pos + 1];
}

t_token	**agregate_spaces(t_token **tokens, int size)
{
	t_token	**agreg;
	int		i;
	int		j;

	agreg = malloc((size + 1) * sizeof(t_token *));
	if (!agreg)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (!tokens[i + 1] || tokens[i + 1]->type == TOK_SPACE)
		{
			tokens[i]->tok_num = j;
			agreg[j++] = tokens[i];
			token_destroy(tokens[i + 1]);
			i += 2;
		}
		else
			agreg_two(tokens, i);
	}
	agreg[j] = NULL;
	free(tokens);
	return (agreg);
}
