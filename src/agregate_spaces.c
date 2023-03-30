/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregate_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:22:26 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 13:47:09 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/tokenizer.h"

static void	agreg_two_to_one_word(t_token **tokens, int *pos)
{
	char	*temp;
	int		i;

	i = *pos;
	if (!tokens[*pos]->to_be_removed)
	{
		temp = tokens[*pos]->content;
		tokens[*pos]->content = ft_strjoin(temp, tokens[*pos + 1]->content);
		free(temp);
		token_destroy(tokens[*pos + 1]);
		while (tokens[++i])
			tokens[i] = tokens[i + 1];
	}
	else
		(*pos)++;
}

static	void	remove_spaces(t_token **agreg, t_token **tokens,
		int *i, int *j)
{
	agreg[(*j)++] = tokens[*i];
	if (tokens[*i + 1] && tokens[*i + 1]->type == TOK_SPACE)
	{
		token_destroy(tokens[*i + 1]);
		*i += 2;
	}
	else
		*i += 1;
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
		if (!tokens[i])
			break ;
		if (tokens[i + 1] && tokens[i]->type == TOK_WORD
			&& tokens[i + 1]->type == TOK_WORD)
			agreg_two_to_one_word(tokens, &i);
		else
			remove_spaces(agreg, tokens, &i, &j);
	}
	agreg[j] = NULL;
	free(tokens);
	return (agreg);
}
