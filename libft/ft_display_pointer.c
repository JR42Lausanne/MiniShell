/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:06 by graux             #+#    #+#             */
/*   Updated: 2022/10/22 10:27:13 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "libft.h"

static int	ft_ptr_len(unsigned long long num)
{
	int					len;

	len = 0;
	if (num == 0)
		return (3);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len + 2);
}

static void	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n >= 16)
	{
		ft_putptr_fd(n / 16, fd);
		ft_putptr_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(n - 10 + 'a', fd);
	}
}

void	ft_display_pointer(t_md *md)
{
	void				*ptr;
	unsigned long long	num;

	ptr = va_arg(md->args, void *);
	num = (unsigned long long) ptr;
	md->total_len += ft_ptr_len(num);
	write(1, "0x", 2);
	ft_putptr_fd(num, 1);
}
