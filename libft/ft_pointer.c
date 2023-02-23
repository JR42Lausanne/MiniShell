/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:15:15 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/31 10:58:20 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countpointer(unsigned long long argument)
{
	int	i;

	i = 2;
	if (argument == 0)
		return (3);
	while (argument != 0)
	{
		i++;
		argument /= 16;
	}
	return (i);
}

static void	ft_putpointer(unsigned long long argument)
{
	if (argument >= 0 && argument <= 9)
	{
		ft_putchar(argument + '0');
	}
	else if (argument >= 10 && argument <= 15)
	{
		ft_putchar(argument - 10 + 'a');
	}
	else
	{
		ft_putpointer(argument / 16);
		ft_putpointer(argument % 16);
	}
}

int	ft_pointer(va_list args)
{
	void	*argument;

	argument = va_arg(args, void *);
	write(1, "0x", 2);
	ft_putpointer((unsigned long long) argument);
	return (ft_countpointer((unsigned long long)argument));
}
