/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_gen_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:36:41 by graux             #+#    #+#             */
/*   Updated: 2023/04/05 16:38:15 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ms_gen_prompt(char prompt[PROMPT_SIZE], int status)
{
	int		pos;
	char	*str;
	int		offset;

	printf("%s", GREEN);
	prompt[0] = '(';
	pos = 1;
	str = ft_itoa(status);
	ft_memcpy(prompt + pos, str, ft_strlen(str));
	pos += ft_strlen(str);
	free(str);
	prompt[pos++] = ')';
	prompt[pos++] = ' ';
	str = ms_getenv_cont("PWD");
	offset = 0;
	if (ft_strlen(str) + pos > PROMPT_SIZE - 5)
	{
		offset = ft_strlen(str) - (PROMPT_SIZE - 5 - pos) + 4;
		ft_memcpy(prompt + pos, "/...", 4);
		pos += 4;
	}
	ft_memcpy(prompt + pos, str + offset, ft_strlen(str + offset));
	pos += ft_strlen(str + offset);
	free(str);
	ft_memcpy(prompt + pos, RESET "\n$> ", 9);
}
