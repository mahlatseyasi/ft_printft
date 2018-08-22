/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:55:58 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:32:25 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "parse_handlers.h"
#include "utils.h"
#include "libft/libft.h"

char	*ft_printf_parse_flags(char **format, t_arg *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+' || **format == ' ')
	{
		if (**format == '#')
			arg->force_prefix = 1;
		else if (**format == '0')
			arg->pad_zeroes = 1;
		else if (**format == '-')
			arg->right_pad = 1;
		else if (**format == '+')
			arg->force_sign = 1;
		else if (**format == ' ')
			arg->blank_sign = 1;
		if (arg->right_pad)
			arg->pad_zeroes = 0;
		return (ft_printf_parse_flags(format, arg));
	}
	else
		return(*format);
}

char	*ft_printf_parse_width(char **format, va_list *list, t_arg *arg)
{
	int got;

	arg->width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			got = va_arg(*list, int);
			if (got < 0)
				arg->right_pad = 1;
			arg->width = got < 0 ? -got : got;
			arg->got_width = 1;
		}
		if (ft_isdigit(**format))
		{
			arg->got_width = 1;
			arg->width = 0;
			while (ft_isdigit(**format))
				arg->width = arg->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*ft_printf_parse_precision(char **format, va_list *list, t_arg *arg)
{
	int prec;

	if (**format == '.')
	{
		if (**format == '*')
		{
			if ((prec = va_arg(*list, int)) >= 0)
			{
				arg->got_precision = 1;
				arg->precision = prec;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				arg->precision = arg->precision * 10 + (*(*format)++ - '0');
			arg->got_precision = 1;
			return (*format);
		}
	}
	else
		return (*format);
}

char	*ft_printf_parse_length(char **format, t_arg *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->length = hh;
		return (*format += 2);
	}
	else if (**format == 'l' || *(*format + 1) == 'l')
	{
		arg->length = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' || **format == 'z')
	{
		if (**format == 'h')
			arg->length = h;
		if (**format == 'l')
			arg->length = l;
		if (**format == 'j')
			arg->length = j;
		if (**format == 'z')
			arg->length = z;
		return (*format++);
	}
	else
		return (*format);
}
