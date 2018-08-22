/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:45:18 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/02 09:12:12 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "libft/libft.h"
#include "utils.h"

ssize_t ft_printf_handle_char(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	if (arg->length == 1)
		return (ft_printf_handle_wchar(format, args, arg));
	else
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->got_width && arg->right_pad)
			ft_printf_width_pad(1, arg->width, ' ');
		return (arg->width ? FT_MAX(arg->width, 1) : 1);
	}
}
