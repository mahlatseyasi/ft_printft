/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:25:08 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 11:24:36 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

ssize_t			ft_get_str(char **format, va_list *args, t_arg *arg)
{
	char	*str;
	size_t	len;

	if (arg->length == 1)
		return (ft_get_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(NULL)";
		len = arg->got_prec ? ft_strlen_fd(str,
				arg->precision) : ft_strlen(str);
		if (arg->got_width && !arg->right_pad)
			ft_width_pad(len, arg->width, arg->pad_zero ? '0' : ' ');
		ft_putnstr(str, len);
		if (arg->got_width && arg->right_pad)
			ft_width_pad(len, arg->width, ' ');
		return (arg->got_width ? ft_maxi(len, arg->width) : len);
	}
}

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

ssize_t			ft_get_wstr(char **format, va_list *args, t_arg *arg)
{
	wchar_t	*str;
	size_t	len;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(NULL)";
	len = arg->got_prec ? calc_wstrlen(str,
			arg->precision, 0) : ft_wstrlen(str);
	ft_wstrlen(str);
	if (arg->got_width && !arg->right_pad)
		ft_width_pad(len, arg->width, arg->pad_zero ? '0' : ' ');
	ft_wputstr_fd(str, len);
	if (arg->got_width && arg->right_pad)
		ft_width_pad(len, arg->width, ' ');
	return (arg->got_width ? ft_maxi(len, arg->width) : len);
}
