/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:25:08 by mkhoza            #+#    #+#             */
/*   Updated: 2018/07/30 12:52:11 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "parse_handlers.h"
#include "utils.h"
#include "libft/libft.h"

ssize_t	ft_printf_handle_str(char **format, va_list *args, t_arg *arg)
{
	char	*str;
	size_t	len;

	if (arg->length == 1)
		return (ft_printf_handle_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(NULL)";
		len = arg->got_precision ? ft_strlen_fd(str, arg->precision) : ft_strlen(str);
		if (arg->got_width && !arg->right_pad)
			ft_printf_width_pad(len, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putnstr(str, len);
		if (arg->got_width && arg->right_pad)
			ft_printf_width_pad(len, arg->width, ' ');
		return (arg->got_width ? FT_MAX(len, arg->width) : len);
	}
}
