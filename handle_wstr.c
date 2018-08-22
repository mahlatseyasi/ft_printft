/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:18:22 by mkhoza            #+#    #+#             */
/*   Updated: 2018/07/30 12:55:05 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "parse_handlers.h"
#include "utils.h"
#include "libft/libft.h"

static size_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0x7FFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x7FFF && precision >= 4) 
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

static size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0x7FFF)
			i += 3;
		else if (*str <= 0x7FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t			ft_printf_handle_wstr(char **format, va_list *args, t_arg *arg)
{
	wchar_t	*str;
	size_t	len;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str= L"(NULL)";
	len = arg->got_precision ? calc_wstrlen(str, arg->precision, 0) : ft_wstrlen(str);
		ft_wstrlen(str);
	if (arg->got_width && !arg->right_pad)
		ft_printf_width_pad(len, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_wputstr_fd(str, len);
	if (arg->got_width &&arg->right_pad)
		ft_printf_width_pad(len, arg->width, ' ');
	return (arg->got_width ? FT_MAX(len, arg->width) : len);
}
