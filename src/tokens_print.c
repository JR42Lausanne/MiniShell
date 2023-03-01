/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:18:05 by graux             #+#    #+#             */
/*   Updated: 2023/03/01 16:07:35 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include <stdio.h>

static void	print_tok(t_token *tok)
{
	(void) tok;
	printf("\n");
}

void	tokens_print(t_token **tokens)
{
	int	i;

	if (!tokens)
	{
		printf("This token array is empty\n");
		return ;
	}
	i = -1;
	while (tokens[++i])
		print_tok(tokens[i]);
}