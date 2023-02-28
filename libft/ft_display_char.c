/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:12:43 by graux             #+#    #+#             */
/*   Updated: 2022/10/19 20:21:17 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_format.h"
#include <unistd.h>

void	ft_display_char(t_md *md)
{
	char	c;
	int		i;

	c = (char) va_arg(md->args, int);
	i = 0;
	if (md->dash)
	{
		md->total_len += write(1, &c, 1);
		while (++i < md->width)
			md->total_len += write(1, " ", 1);
	}
	else
	{
		while (++i < md->width - 1)
			md->total_len += write(1, " ", 1);
		md->total_len += write(1, &c, 1);
	}
	md = ft_reset_format(md);
}
