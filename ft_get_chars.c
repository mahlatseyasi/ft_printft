/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:45:18 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 11:43:22 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

ssize_t	ft_get_char(char **format, va_list *args, t_arg *arg)
{
	format = 0;
	if (arg->length == 1)
		return (ft_get_wchar(format, args, arg));
	else
	{
		if (arg->got_width && !arg->right_pad)
			ft_width_pad(1, arg->width, arg->pad_zero ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->got_width && arg->right_pad)
			ft_width_pad(1, arg->width, ' ');
		return (arg->width ? ft_maxi(arg->width, 1) : 1);
	}
}

ssize_t	ft_get_wchar(char **format, va_list *args, t_arg *arg)
{
	wchar_t			chr;
	unsigned int	chr_len;

	format = 0;
	chr = (wchar_t)va_arg(*args, wint_t);
	if (chr <= 0x7F)
		chr_len = 1;
	if (chr <= 0x7FF)
		chr_len = 2;
	if (chr <= 0x7FFF)
		chr_len = 3;
	if (chr <= 0x7FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->got_width && !arg->right_pad)
		ft_width_pad(chr_len, arg->width, arg->pad_zero ? '0' : ' ');
	ft_wputchar(chr);
	if (arg->got_width && arg->right_pad)
		ft_width_pad(chr_len, arg->width, arg->pad_zero ? '0' : ' ');
	return (arg->got_width ? ft_maxi(chr_len, arg->width) : chr_len);
}
