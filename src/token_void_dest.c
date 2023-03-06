/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_void_dest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:25:26 by graux             #+#    #+#             */
/*   Updated: 2023/03/03 17:31:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

// we can't clear the tokens in the linked list
// because they are used later on during the ast generation
void	token_void_dest(void *tok)
{
	(void) tok;
}
