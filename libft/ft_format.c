/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:46:04 by graux             #+#    #+#             */
/*   Updated: 2022/10/22 12:34:13 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include "ft_format.h"
#include "ft_specifier.h"

t_md	*ft_reset_format(t_md *md)
{
	md->width = 0;
	md->precision = 0;
	md->zero_pad = 0;
	md->point = 0;
	md->dash = 0;
	md->sign = 0;
	md->is_zero = 0;
	md->percent = 0;
	md->space = 0;
	md->hashtag = 0;
	return (md);
}

t_md	*ft_init_format(t_md *md)
{
	md = ft_reset_format(md);
	md->total_len = 0;
	return (md);
}

// %[flags][width][.precision][length]specifier
// flags: "-0#+ "
void	ft_handle_flags(int *pos, t_md *md, const char *format)
{
	while (ft_strchr("-+ #0", format[*pos]))
	{
		if (format[*pos] == '-')
			md->dash = 1;
		if (format[*pos] == '+')
			md->sign = 1;
		if (format[*pos] == ' ')
			md->space = 1;
		if (format[*pos] == '#')
			md->hashtag = 1;
		if (format[*pos] == '0')
			md->zero_pad = 1;
		(*pos)++;
	}
	ft_handle_width(pos, md, format);
}

void	ft_handle_width(int *pos, t_md *md, const char *format)
{
	int		i;
	int		width_len;
	char	*width_str;

	width_len = ft_num_size(*pos, format);
	width_str = malloc((width_len + 1) * sizeof(char));
	if (width_str == NULL)
		return ;
	i = 0;
	while (i < width_len)
	{
		width_str[i] = format[*pos + i];
		i++;
	}
	width_str[i] = '\0';
	md->width = ft_atoi(width_str);
	free(width_str);
	*pos += i;
	ft_handle_prec(pos, md, format);
}

void	ft_handle_prec(int *pos, t_md *md, const char *format)
{
	int		i;
	int		prec_len;
	char	*prec_str;

	if (format[*pos] == '.')
	{
		prec_len = ft_num_size(*pos, format);
		prec_str = malloc((prec_len + 1) * sizeof(char));
		if (prec_str == NULL)
			return ;
		i = 0;
		while (i < prec_len)
		{
			prec_str[i] = format[*pos + i];
			i++;
		}
		prec_str[i] = '\0';
		md->precision = ft_atoi(prec_str);
		free(prec_str);
		*pos += i;
		ft_handle_specifier(pos, md, format);
	}
	else
		ft_handle_specifier(pos, md, format);
}
