/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:56:24 by jlaiti            #+#    #+#             */
/*   Updated: 2022/10/18 15:00:42 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static	int	numb_int(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter = 1;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter + 1);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	t;

	i = 0;
	size = 0;
	while (str[size] != '\0')
		size++;
	while (i < size / 2)
	{
		t = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = t;
		i++;
	}
	return (str);
}

static char	*ft_itoa_long(long n)
{
	int		i;
	char	*new;
	int		isneg;

	isneg = 0;
	i = 0;
	new = (char *)malloc(sizeof(char) * numb_int(n));
	if (new == 0)
		return (0);
	if (n < 0)
	{	
		isneg = 1 ;
		n = -n;
	}
	while (n >= 0)
	{
		new[i++] = n % 10 + '0';
		n = n / 10;
		if (n == 0)
			n = -1;
	}
	if (isneg)
		new[i++] = '-';
	new[i] = '\0';
	return (ft_strrev(new));
}

char	*ft_itoa(int n)
{
	long	nb;

	nb = n;
	return (ft_itoa_long(nb));
}
/*
int main(void)
{
	int n;
	n = 0;

	printf("la chaine de caractere est %s\n", ft_itoa(n));

	return (0);

}*/
