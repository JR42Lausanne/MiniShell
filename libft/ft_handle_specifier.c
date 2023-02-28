/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:35:30 by graux             #+#    #+#             */
/*   Updated: 2022/10/20 16:27:15 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_specifier.h"
#include <unistd.h>
#include <stdarg.h>

// specifiers: : cspdiuxX%
void	ft_handle_specifier(int *pos, t_md *md, const char *format)
{
	if (format[*pos] == 'c')
		ft_display_char(md);
	else if (format[*pos] == 's')
		ft_display_str(md);
	else if (format[*pos] == 'p')
		ft_display_pointer(md);
	else if (format[*pos] == 'u')
		ft_display_unsigned(md);
	else if (format[*pos] == 'i' || format[*pos] == 'd')
		ft_display_decimal(md);
	else if (format[*pos] == 'x' || format[*pos] == 'X')
		ft_display_hex(*pos, md, format);
	else if (format[*pos] == '%')
		md->total_len += write(1, "%", 1);
	(*pos)++;
}
