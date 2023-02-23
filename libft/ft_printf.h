/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:37:39 by jlaiti            #+#    #+#             */
/*   Updated: 2022/11/30 10:20:52 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_check_args(va_list args, const char *format, int *len);
void	ft_putchar(char c);
int		ft_number(va_list args);
int		ft_string(va_list args);
int		ft_unsigned_int(va_list args);
int		ft_hexa(va_list args, const char format);
int		ft_pointer(va_list args);
int		ft_char(va_list	args);

#endif
