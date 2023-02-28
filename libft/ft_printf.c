/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:18:53 by graux             #+#    #+#             */
/*   Updated: 2022/11/03 16:33:34 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	t_md		*md;
	int			printed_chars;
	int			i;

	i = 0;
	printed_chars = 0;
	md = (t_md *) malloc(sizeof(t_md));
	if (md == NULL)
		return (-1);
	md = ft_init_format(md);
	va_start(md->args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_handle_flags(&(i), md, format);
		}
		else
			printed_chars += write(1, &format[i++], 1);
	}
	va_end(md->args);
	printed_chars += md->total_len;
	free(md);
	return (printed_chars);
}
