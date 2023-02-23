/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:07:46 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/31 10:54:57 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter_arg(int argument)
{
	int	i;
	int	t;

	i = 0;
	if (argument == 0)
		return (1);
	t = argument;
	while (argument != 0)
	{
		i++;
		argument /= 10;
	}
	if (t < 0)
		return (i + 1);
	else
		return (i);
}

int	ft_number(va_list args)
{
	int	argument;

	argument = va_arg(args, int);
	ft_putnbr_fd(argument, 1);
	return (ft_counter_arg(argument));
}
