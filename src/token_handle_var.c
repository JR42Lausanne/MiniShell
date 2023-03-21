/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:08:53 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 13:18:13 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"
#include "../include/libft.h"

int	token_var_len(t_tokenizer *toker)
{
	int	size;

	if (toker->input[toker->pos] && (!ft_isalpha(toker->input[toker->pos])
			&& toker->input[toker->pos] != '_'))
		return (1);
	size = 0;
	while (toker->input[toker->pos + size] == '_'
		|| ft_isalnum(toker->input[toker->pos + size]))
	{
		size++;
	}
	return (size);
}

static int	handle_size_one(t_tokenizer *toker, t_token *tok)
{
	if (toker->input[toker->pos] == '~')
	{
		token_gen_content(tok, "$~", 2);
		toker->pos++;
		return (1);
	}
	else if (toker->input[toker->pos] == ' '
		|| toker->input[toker->pos] == '\t')
	{
		token_gen_content(tok, "$", 1);
		return (1);
	}
	return (0);
}

void	token_handle_var(t_tokenizer *toker, t_token *tok)
{
	int		size_in_input;
	char	*var_name;
	char	*var_value;

	var_value = NULL;
	tok->type = TOK_VAR;
	toker->pos++;
	size_in_input = token_var_len(toker);
	if (handle_size_one(toker, tok))
		return ;
	var_name = ft_substr(toker->input, toker->pos, size_in_input);
	if (var_name)
	{
		var_value = ms_getenv(var_name); // TODO protection
		if (!var_value)
		{
			token_gen_content(tok, "", 0);
			toker->pos += size_in_input;
			tok->to_be_removed = 1;
			return ;
		}
		token_gen_content(tok, var_value + size_in_input + 1,
			ft_strlen(var_value + size_in_input + 1));
		free(var_name);
		free(var_value);
	}
	toker->pos += size_in_input;
}
