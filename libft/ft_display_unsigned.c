/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:31:54 by graux             #+#    #+#             */
/*   Updated: 2022/10/20 16:31:02 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "libft.h"

static void	ft_plus(int *i, t_md *md)
{
	if (md->sign)
	{
		md->total_len += write(1, "+", 1);
		(*i)++;
	}
}

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static void	ft_putnbr_unsigned_fd_rec(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned_fd_rec(n / 10, fd);
		ft_putnbr_unsigned_fd_rec(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	ft_putnbr_unsigned_fd_rec(n, fd);
}

void	ft_display_unsigned(t_md *md)
{
	int				i;
	unsigned int	num;

	num = va_arg(md->args, unsigned int);
	i = 0;
	if (md->dash)
	{
		ft_plus(&i, md);
		ft_putnbr_unsigned_fd(num, 1);
		md->total_len += ft_num_len(num);
		i += ft_num_len(num);
		while (i++ < md->width)
			md->total_len += write(1, " ", 1);
	}
	else
	{
		while (i < md->width && md->width - i < ft_num_len(num))
		{
			md->total_len += write(1, " ", 1);
			i++;
		}
		ft_plus(&i, md);
		ft_putnbr_unsigned_fd(num, 1);
		md->total_len += ft_num_len(num);
	}
}
