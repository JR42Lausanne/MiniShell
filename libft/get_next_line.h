/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:35:52 by jlaiti            #+#    #+#             */
/*   Updated: 2023/01/26 10:05:41 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# define MAX_FD 4096

char	*ft_join(char *s1, char *s2);
int		ft1_strlen(char *str);
int		ft1_strchr(char *s, char c);
char	*get_next_line(int fd);

#endif
