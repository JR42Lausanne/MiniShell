/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:50:35 by graux             #+#    #+#             */
/*   Updated: 2022/10/10 12:43:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		result;
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
