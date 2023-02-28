/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:32:52 by graux             #+#    #+#             */
/*   Updated: 2022/10/20 16:27:11 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPECIFIER_H
# define FT_SPECIFIER_H

# include "ft_format.h"

void	ft_handle_specifier(int *pos, t_md *md, const char *format);
void	ft_display_char(t_md *md);
void	ft_display_str(t_md *md);
void	ft_display_pointer(t_md *md);
void	ft_display_decimal(t_md *md);
void	ft_display_unsigned(t_md *md);
void	ft_display_hex(int pos, t_md *md, const char *format);

#endif
