/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_gen_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:25:32 by graux             #+#    #+#             */
/*   Updated: 2023/03/02 09:32:47 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/libft.h"

void	token_gen_content(t_token *tok, char *src, int size)
{
	tok->content = malloc((size + 1) * sizeof(char));
	if (!tok->content)
		return ;
	ft_memcpy(tok->content, src, size);
	tok->content[size] = '\0';
}
