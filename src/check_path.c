/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:16 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/28 14:42:44 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "libft"

char	*check_path(char	*env)
{
	int	i;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH", ft_strlen(env[i])))
		i++;
	return (env[i] + 5);
}
