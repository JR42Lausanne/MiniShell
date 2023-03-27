/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:35:57 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/27 16:20:00 by graux            ###   ########.fr       */
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

static int	is_match(char *name, char *expr)
{
	//TODO fix echo *e not matching Makefile
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (name[0] == '.' && expr[0] != '.')
		return (0);
	printf("is match for %s\n", name);
	while (expr[i] && name[j])
	{
		if (expr[i] == '*')
		{
			while (name[j] && name[j] != expr[i + 1])
				j++;
			i += 1;
		}
		if (expr[i] && expr[i++] != name[j++])
			return (0);
	}
	if (expr[i] == name[j] || expr[i] == '*')
		return (1);
	return (0);
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
			if (is_match(entry->d_name, tok->content))
				add_to_matches(&matches, entry->d_name);
			entry = readdir(dirp);
		}
	}
	closedir(dirp);
	return (matches);
}
