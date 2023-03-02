/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:59:12 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 16:39:27 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"
#include "../include/libft.h"
#include <stdlib.h>

void	tokenizer_destroy(t_tokenizer *toker)
{
	if (!toker)
		return ;
	ft_lstclear(&toker->tokens, token_void_dest);
	free(toker->input);
	free(toker);
}
