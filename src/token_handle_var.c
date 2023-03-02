/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:08:53 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 12:18:44 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/libft.h"

static int	var_len(t_tokenizer *toker)
{
	int	size;

	size = 0;
	while (toker->input[toker->pos + size] == '_'
		|| ft_isalpha(toker->input[toker->pos + size]))
	{
		size++;
	}
	return (size);
}

void	token_handle_var(t_tokenizer *toker, t_token *tok)
{
	int	size_in_input;

	printf("hey there");
	tok->type = TOK_VAR;
	toker->pos++;
	size_in_input = var_len(toker);
	toker->pos += size_in_input;
	printf("%d\n", size_in_input);
}
