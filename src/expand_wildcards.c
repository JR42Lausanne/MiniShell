/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:12:14 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 13:52:32 by graux            ###   ########.fr       */
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

static int	find_wildcard(t_token **tokens)
{
	int		i;

	i = 0;
	while (tokens[i] && tokens[i]->type != TOK_WILDCARD)
		i++;
	return (i);
}

static t_token	*select_toks_or_match(t_token **tokens, char **matches,
		int i, int j)
{
	if (j < i)
		return (tokens[j]);
	else if (j >= i + matches_len(matches))
		return (tokens[j - matches_len(matches) + 1]);
	else
		return (token_from_char(matches[j - i]));
}

static t_token	**expand_one(t_token **tokens, int size)
{
	t_token	**exp;
	char	**matches;
	int		wild_pos;
	int		j;

	j = -1;
	wild_pos = find_wildcard(tokens);
	if (!tokens[wild_pos])
		return (tokens);
	matches = match_wildcard(tokens[wild_pos]);
	if (!matches)
	{
		tokens[wild_pos]->type = TOK_WORD;
		return (tokens);
	}
	exp = ft_calloc(size + 1 + matches_len(matches), sizeof(t_token *));
	if (!exp)
		return (NULL);
	while (++j < size - 1 + matches_len(matches))
		exp[j] = select_toks_or_match(tokens, matches, wild_pos, j);
	token_destroy(tokens[wild_pos]);
	//TODO free matches
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
