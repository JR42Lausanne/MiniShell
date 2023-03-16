/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:21:59 by graux             #+#    #+#             */
/*   Updated: 2023/03/16 15:03:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

static void	to_words(t_token **tokens)
{
	int		i;
	int		size;

	size = tokens_size(tokens);
	i = -1;
	while (++i < size)
	{
		if (tokens[i]->type == TOK_SQ || tokens[i]->type == TOK_DQ
			|| tokens[i]->type == TOK_VAR)
			tokens[i]->type = TOK_WORD;
	}
}

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

static t_token	**agregate_spaces(t_token **tokens)
{
	t_token	**agreg;
	int		i;
	int		j;
	int		size;

	size = tokens_size(tokens);
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
			agreg_two(tokens, i); //TODO if next is not space agregate and stay in same pos
	}
	agreg[j] = NULL;
	free(tokens);
	return (agreg);
}

t_token	**tokenize_input(char *input)
{
	t_tokenizer	*toker;
	t_token		**tokens;

	toker = tokenizer_create(input);
	tokens = tokenizer_parse(toker);
	to_words(tokens);
	tokens = agregate_spaces(tokens);
	tokenizer_destroy(toker);
	return (tokens);
}
