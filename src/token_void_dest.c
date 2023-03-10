/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_void_dest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:25:26 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 16:26:29 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

void	token_void_dest(void *tok)
{
	token_destroy((t_token *) tok);
}
