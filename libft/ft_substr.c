/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:20:50 by graux             #+#    #+#             */
/*   Updated: 2022/10/11 17:21:03 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

static int	ft_calclen(size_t slen, unsigned int start, size_t len)
{
	if (start > slen)
		return (0);
	if (len > slen)
		return (slen - start);
	else if (len == 0)
		return (0);
	else if (start == 0)
		return (len);
	else
		return (ft_min(slen - start, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			slen;
	unsigned int	i;

	slen = ft_strlen(s);
	substr = malloc((ft_calclen(slen, start, len) + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && start + i < slen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
