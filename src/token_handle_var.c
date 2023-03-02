/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:08:53 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 15:05:36 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/minishell.h"
#include "../include/libft.h"

static int	var_len(t_tokenizer *toker)
{
	int	size;

	size = 0;
	while (toker->input[toker->pos + size] == '_'
		|| ft_isalnum(toker->input[toker->pos + size]))
	{
		size++;
	}
	return (size);
}

void	token_handle_var(t_tokenizer *toker, t_token *tok)
{
	int		size_in_input;
	char	*var_name;
	char	*var_value;

	var_value = NULL;
	tok->type = TOK_VAR;
	toker->pos++;
	size_in_input = var_len(toker);
	var_name = ft_substr(toker->input, toker->pos, size_in_input);
	if (var_name)
	{
		var_value = ms_getenv(var_name); // TODO protection
		if (!var_value)
		{
			token_gen_content(tok, "", 0);
			toker->pos += size_in_input;
			return ;
		}
		token_gen_content(tok, var_value + size_in_input + 1,
			ft_strlen(var_value + size_in_input + 1));
		free(var_name);
		free(var_value);
	}
	toker->pos += size_in_input;
}
