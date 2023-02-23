/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:41:56 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/31 10:53:40 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_args(va_list args, const char *format, int *len)
{
	if (*format == 'd' || *format == 'i')
		*len += ft_number(args);
	else if (*format == 's')
		*len += ft_string(args);
	else if (*format == 'p')
		*len += ft_pointer(args);
	else if (*format == 'c')
		*len += ft_char(args);
	else if (*format == 'u')
		*len += ft_unsigned_int(args);
	else if (*format == 'x' || *format == 'X')
		*len += ft_hexa(args, *format);
	else if (*format == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
}
