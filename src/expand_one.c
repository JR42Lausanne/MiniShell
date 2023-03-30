/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:31 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 15:02:17 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

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

t_token	**expand_one(t_token **tokens, int size)
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
