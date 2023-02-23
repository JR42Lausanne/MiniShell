/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:40:35 by graux             #+#    #+#             */
/*   Updated: 2023/02/06 15:49:09 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "color.h"
#include <unistd.h>

static void	put_chr(char c)
{
	write(1, &c, 1);
}

void	put_str(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	put_nbr(size_t nbr)
{
	if (nbr >= 10)
	{
		put_nbr(nbr / 10);
		put_nbr(nbr % 10);
	}
	else
		put_chr(nbr + '0');
}

void	put_routine_title(const char *title)
{
	put_str("--------------- "MAGENTA);
	put_str(title);
	put_str(RESET" ---------------\n\n");
}
