/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:45:38 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:25:38 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "libft/libft.h"
#include "utils.h"

ssize_t	ft_printf_handle_wchar(char **format, va_list *args, t_arg *arg)
{
	wchar_t		chr;
	unsigned int	chr_len;

	(void)format;
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
		ft_printf_width_pad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_wputchar(chr);
	if (arg->got_width && arg->right_pad)
		ft_printf_width_pad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? FT_MAX(chr_len, arg->width) : chr_len);
}
