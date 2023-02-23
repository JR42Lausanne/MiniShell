/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:08:25 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/31 10:58:52 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(va_list args)
{	
	char	*chaine;

	chaine = va_arg(args, char *);
	if (chaine == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(chaine, 1);
	return (ft_strlen(chaine));
}
