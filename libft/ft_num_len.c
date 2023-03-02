/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:13:36 by graux             #+#    #+#             */
/*   Updated: 2022/10/22 12:33:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_num_size(int pos, const char *format)
{
	int	len;

	len = 0;
	while (ft_isdigit(format[pos++]))
		len++;
	return (len);
}
