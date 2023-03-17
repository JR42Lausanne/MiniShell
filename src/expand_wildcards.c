/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:12:14 by graux             #+#    #+#             */
/*   Updated: 2023/03/17 17:20:54 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <dirent.h>

static int	matches_len(char **matches)
{
	int	len;

	len = 0;
	if (!matches)
	{
		fprintf(stderr, "matches is null\n");
		return (0);
	}
	while (matches[len])
		len++;
	return (len);
}

static int	is_match(char *name, char *expr)
{
	printf("%s compared to %s\n", name, expr);
	return (0);
}

static void	add_to_matches(char ***matches, char *to_add)
{
	(void) matches;
	(void) to_add;
}

static char	**match_wildcard(t_token *tok)
{
	char			**matches;
	DIR				*dirp;
	struct dirent	*entry;

	matches = NULL;
	dirp = opendir(".");
	if (dirp)
	{
		entry = readdir(dirp);
		while (entry)
		{
			if (is_match(entry->d_name, tok->content))
				add_to_matches(&matches, entry->d_name);
			entry = readdir(dirp);
		}
	}
	closedir(dirp);
	token_destroy(tok);
	return (matches);
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
	while (tokens[i] && tokens[i]->type == TOK_WILDCARD)
		i++;
	if (tokens[i])
	{
		matches = match_wildcard(tokens[i]);
		exp = ft_calloc(size + 1 + matches_len(matches), sizeof(t_token *));
		if (!exp)
			return (NULL);
		while (++j < size + matches_len(matches))
		{
			if (j < i || j >= i + matches_len(matches))
				exp[j] = tokens[i];
			else
				exp[j] = token_from_char(matches[j - i]);
		}
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
	int		max_deb;

	max_deb = 5;
	expanded = tokens;
	size = tokens_size(tokens);
	while (contain_wild(expanded, size) && max_deb--)
	{
		expanded = expand_one(expanded, size);
		size = tokens_size(expanded);
	}
	//free(tokens); //TODO uncomment
	return (expanded);
}
