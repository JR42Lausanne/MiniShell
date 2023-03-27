/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:12:14 by graux             #+#    #+#             */
/*   Updated: 2023/03/27 14:07:42 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <dirent.h>

static int	matches_len(char **matches)
{
	int	len;

	len = 0;
	if (!matches)
		return (0);
	while (matches[len])
		len++;
	return (len);
}

static t_token	*token_from_char(char *str)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = TOK_WORD;
	token_gen_content(tok, str, ft_strlen(str));
	return (tok);
}

static t_token	**expand_one(t_token **tokens, int size)
{
	t_token	**exp;
	char	**matches;
	int		i;
	int		j;

	i = 0;
	j = -1;
	exp = tokens;
	while (tokens[i] && tokens[i]->type != TOK_WILDCARD)
		i++;
	if (tokens[i])
	{
		matches = match_wildcard(tokens[i]);
		exp = ft_calloc(size + 1 + matches_len(matches), sizeof(t_token *));
		if (!exp)
			return (NULL);
		while (++j < size - 1 + matches_len(matches))
		{
			if (j < i)
				exp[j] = tokens[j];
			else if (j >= i + matches_len(matches))
				exp[j] = tokens[j - matches_len(matches) + 1];
			else
				exp[j] = token_from_char(matches[j - i]);
		}
		token_destroy(tokens[i]);
		//TODO free matches
	}
	return (exp);
}

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
	int		size;

	expanded = tokens;
	size = tokens_size(tokens);
	while (contain_wild(expanded, size))
	{
		expanded = expand_one(expanded, size);
		size = tokens_size(expanded);
	}
	//free(tokens); //TODO uncomment
	return (expanded);
}
