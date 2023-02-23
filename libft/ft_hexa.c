/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:31:53 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/31 10:56:48 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hexa(unsigned int hexa)
{
	int	i;

	i = 0;
	if (hexa == 0)
		return (1);
	while (hexa != 0)
	{
		hexa /= 16;
		i++;
	}
	return (i);
}

static void	ft_puthexa(unsigned int hexa, int offset)
{
	if (hexa >= 0 && hexa <= 9)
	{
		ft_putchar(hexa + '0');
	}
	else if (hexa >= 10 && hexa <= 15)
	{
		ft_putchar(hexa - 10 + 'a' - offset);
	}
	else
	{
		ft_puthexa(hexa / 16, offset);
		ft_puthexa(hexa % 16, offset);
	}
}

int	ft_hexa(va_list args, const char format)
{
	unsigned int	hexa;

	hexa = va_arg(args, unsigned int);
	if (format == 'x')
		ft_puthexa(hexa, 0);
	if (format == 'X')
		ft_puthexa(hexa, 'a' - 'A');
	return (ft_count_hexa(hexa));
}
