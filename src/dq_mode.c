/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:29:55 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 13:18:25 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"

static int	handle_size_one(t_tokenizer *toker, char **var_value)
{
	if (toker->input[toker->pos] == '~')
	{
		*var_value = ft_strdup("$~");
		toker->pos++;
		return (1);
	}
	else if (toker->input[toker->pos] == ' '
		|| toker->input[toker->pos] == '\t')
	{
		*var_value = ft_strdup("$");
		return (1);
	}
	return (0);
}

static char	*var_mode(t_tokenizer *toker)
{
	char	*var_name;
	char	*var_value;
	int		size;

	toker->pos += 1;
	size = token_var_len(toker);
	if (handle_size_one(toker, &var_value))
		return (var_value);
	var_name = ft_substr(toker->input, toker->pos, size);
	toker->pos += size;
	if (var_name)
	{
		var_value = ms_getenv_cont(var_name);
		if (!var_value)
		{
			var_value = malloc(1 * sizeof(char));
			var_value[0] = '\0';
		}
		free(var_name);
		return (var_value);
	}
	var_value = malloc(1 * sizeof(char));
	var_value[0] = '\0';
	return (var_value);
}

static char	*string_mode(t_tokenizer *toker)
{
	char	*string;
	int		size;

	size = 0;
	while (toker->input[toker->pos + size] != '$'
		&& toker->input[toker->pos + size] != '"')
	{
		size++;
	}
	string = ft_substr(toker->input, toker->pos, size);
	toker->pos += size;
	return (string);
}

static void	fill_token(t_tokenizer *toker, t_token *tok)
{
	char	*curr_string;
	char	*tot_string;
	char	*old;
	int		first_pass;

	first_pass = 0;
	tot_string = NULL;
	while (toker->input[toker->pos] != '"')
	{
		if (toker->input[toker->pos] == '$')
			curr_string = var_mode(toker);
		else
			curr_string = string_mode(toker);
		if (!first_pass++)
			tot_string = curr_string;
		else
		{
			old = tot_string;
			tot_string = ft_strjoin(tot_string, curr_string);
			free(old);
		}
	}
	token_gen_content(tok, tot_string, ft_strlen(tot_string));
}

void	dq_mode(t_tokenizer *toker, t_token *tok)
{
	char	*closing_sq;

	tok->type = TOK_DQ;
	toker->pos += 1;
	closing_sq = ft_strchr(toker->input + toker->pos, '"');
	if (!closing_sq)
	{
		token_gen_content(tok, "Invalid dq string", 17);
		tok->type = TOK_INVALID;
		return ;
	}
	fill_token(toker, tok);
	toker->pos += 1;
}
