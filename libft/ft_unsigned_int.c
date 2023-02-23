/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:19:00 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/31 10:57:19 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_unsign(unsigned int argument)
{
	int	i;

	if (argument == 0)
		return (1);
	i = 0;
	while (argument != 0)
	{
		i++;
		argument /= 10;
	}	
	return (i);
}

static void	ft_putunsign(unsigned int argument)
{
	if (argument >= 0 && argument <= 9)
		ft_putchar(argument + '0');
	else
	{	
		ft_putunsign(argument / 10);
		ft_putunsign(argument % 10);
	}		
}

int	ft_unsigned_int(va_list args)
{
	int	argument;

	argument = va_arg(args, unsigned int);
	ft_putunsign(argument);
	return (ft_count_unsign(argument));
}
