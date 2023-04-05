/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:35:57 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/05 12:14:59 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"
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

static char	**setup_lookup(int n, int m, char *pattern)
{
	char	**lookup;
	int		i;

	lookup = ft_calloc((n + 2), sizeof(char *));
	if (!lookup)
		return (NULL);
	i = -1;
	while (++i <= n)
	{
		lookup[i] = ft_calloc(m + 1, sizeof(char));
		if (!lookup[i])
		{
			free_args(lookup);
			return (NULL);
		}
	}
	lookup[0][0] = 1;
	i = 0;
	while (++i <= m)
	{
		if (pattern[i - 1] == '*')
			lookup[0][i] = lookup[0][i - 1];
	}
	return (lookup);
}

static int	is_match(char *name, char *pattern, int n, int m)
{
	char	**lookup;
	int		i;
	int		j;

	lookup = setup_lookup(n, m, pattern);
	if (!lookup)
		return (0);
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= m)
		{
			if (pattern[j - 1] == '*')
				lookup[i][j] = ((lookup[i][j -1] || lookup[i - 1][j])
						&& !(name[i - 1] == '.' && i == 1 && j == 1));
			else if (name[i - 1] == pattern[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1];
			else
				lookup[i][j] = 0;
		}
	}
	i = lookup[n][m];
	free_args(lookup);
	return (i);
}

static void	add_to_matches(char ***matches, char *to_add)
{
	char	**copy;
	int		len;

	if (*matches == NULL)
		*matches = ft_calloc(1, sizeof(char *));
	if (*matches == NULL)
		return ;
	len = matches_len(*matches);
	copy = ft_calloc(len + 2, sizeof(char *));
	ft_memcpy(copy, *matches, len * sizeof(char *));
	copy[len] = ft_strdup(to_add);
	free(*matches);
	*matches = copy;
}

char	**match_wildcard(t_token *tok)
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
			if (is_match(entry->d_name, tok->content,
					ft_strlen(entry->d_name), ft_strlen(tok->content)))
				add_to_matches(&matches, entry->d_name);
			entry = readdir(dirp);
		}
	}
	closedir(dirp);
	return (matches);
}
