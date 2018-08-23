/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:16:41 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:32:06 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

ssize_t	ft_get_escape(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	if (arg->got_width && !arg->right_pad)
		ft_width_pad(1, arg->width, arg->pad_zero ? '0' : ' ');
	ft_putchar('%');
	if (arg->got_width && arg->right_pad)
		ft_width_pad(1, arg->width, ' ');
	return (arg->got_width ? ft_maxi(arg->width, 1) : 1);
}

ssize_t	ft_get_ptr(char **format, va_list *args, t_arg *arg)
{
	char		*base;
	uintmax_t	num;

	(void)format;
	arg->length = z;
	if (arg->got_prec)
		arg->pad_zero = 0;
	base = "0123456789abcdef";
	num = ft_printf_get_unsigned_from_length(args, arg);
	return (ft_printf_nbrforceprefix(num, base, arg, "0x"));
}

ssize_t	ft_get_null(char **format, va_list *args, t_arg *arg)
{
	(void)args;
	if (arg->got_width && !arg->right_pad)
		ft_width_pad(1, arg->width, arg->pad_zero ? '0' : ' ');
	ft_putchar(**format);
	if (arg->got_width && arg->right_pad)
		ft_width_pad(1, arg->width, ' ');
	return (arg->got_width ? ft_maxi(arg->width, 1) : 1);
}
