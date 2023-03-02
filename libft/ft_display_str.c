/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:50 by graux             #+#    #+#             */
/*   Updated: 2022/10/18 15:05:58 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

void	ft_display_str(t_md *md)
{
	int		i;
	char	*str;

	str = va_arg(md->args, char *);
	i = 0;
	if (str)
	{
		if (md->dash)
		{
			while (str[i])
				md->total_len += write(1, &str[i++], 1);
			while (i++ < md->width)
				md->total_len += write(1, " ", 1);
		}
		else
		{
			while (str[i])
				md->total_len += write(1, &str[i++], 1);
			while (i++ < md->width)
				md->total_len += write(1, " ", 1);
		}
	}
	else
		md->total_len += write(1, "(null)", 6);
	md = ft_reset_format(md);
}
