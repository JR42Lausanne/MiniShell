/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:00:51 by graux             #+#    #+#             */
/*   Updated: 2022/10/10 14:43:08 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strrev(char *s, int start, int end)
{
	char	temp;

	if (start < end)
	{
		temp = *(s + start);
		*(s + start) = *(s + end);
		*(s + end) = temp;
		start++;
		end--;
		ft_strrev(s, start, end);
	}
}

static void	ft_itoa_long(char *n_str, long n)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (n == 0)
		n_str[i++] = '0';
	if (n < 0)
	{
		n = (long) -n;
		neg = 1;
	}
	while (n != 0)
	{
		n_str[i++] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		n_str[i++] = '-';
	ft_strrev(n_str, 0, i - 1);
	n_str[i] = '\0';
}

static size_t	ft_intcharlen(long n)
{
	size_t	len;

	if (n == 0)
		return (2);
	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*n_str;

	n_str = malloc(ft_intcharlen(n) * sizeof(char));
	if (n_str == NULL)
		return (NULL);
	ft_itoa_long(n_str, n);
	return (n_str);
}
