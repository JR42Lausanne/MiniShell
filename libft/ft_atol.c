/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:50:35 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 14:53:17 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;
	char	*s_cpy;

	result = 0;
	sign = 1;
	s_cpy = (char *) s;
	if (ft_strlen(s_cpy) == 0)
		return (0);
	while (ft_strchr("\t\n\r\v\f ", *s_cpy))
		s_cpy++;
	if (*s_cpy == '+' && ft_isdigit(*(s_cpy + 1)))
		s_cpy++;
	if (*s_cpy == '-')
	{
		sign = -1;
		s_cpy++;
	}
	while (*s_cpy && ft_isdigit(*s_cpy))
		result = result * 10 + *s_cpy++ - '0';
	return (result * sign);
}
