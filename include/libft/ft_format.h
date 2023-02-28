/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:40:36 by graux             #+#    #+#             */
/*   Updated: 2022/10/22 12:36:46 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_md
{
	va_list	args;
	int		width;
	int		precision;
	int		zero_pad;
	int		point;
	int		dash;
	int		total_len;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
	int		hashtag;
}	t_md;

t_md		*ft_reset_format(t_md *md);
t_md		*ft_init_format(t_md *md);
void		ft_handle_flags(int *pos, t_md *md, const char *format);
void		ft_handle_width(int *pos, t_md *md, const char *format);
void		ft_handle_prec(int *pos, t_md *md, const char *format);
int			ft_width_len(int *pos, const char *format);
int			ft_num_size(int pos, const char *format);

#endif
