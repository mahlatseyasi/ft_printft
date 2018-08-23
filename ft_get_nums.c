/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:46:44 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:50:40 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

ssize_t	ft_get_long(char **format, va_list *args, t_arg *arg)
{
	arg->length = 1;
	return (ft_getter(ft_tolower(**format))(format, args, arg));
}

ssize_t	ft_get_hex(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = ft_printf_get_unsigned_from_length(args, arg);
	if (**format == 'X')
		return (ft_get_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (ft_get_uint(nbr, arg, "0123456789abcdef", "0x"));
}

ssize_t	ft_get_octal(char **format, va_list *args, t_arg *arg)
{
	uintmax_t nbr;

	(void)format;
	nbr = ft_printf_get_unsigned_from_length(args, arg);
	if (arg->push_pref && nbr == 0 && arg->got_prec && arg->precision == 0)
	{
		if (arg->got_width && !arg->right_pad)
			ft_width_pad(1, arg->width, arg->pad_zero ? '0' : ' ');
		ft_putstr("0");
		if (arg->got_width && arg->right_pad)
			ft_width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_maxi(arg->width, 1) : 1);
	}
	else if (arg->push_pref && nbr != 0)
	{
		arg->got_prec = 1;
		arg->precision = ft_maxi(arg->precision,
				ft_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_get_uint(nbr, arg, "01234567", NULL));
}
