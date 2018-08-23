/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:23:19 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:09:33 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static ssize_t	ft_get_arg(char **format, va_list *args, t_arg *arg)
{
	ssize_t		ret;
	t_getter	getter;

	if (*(++*format) == '\0')
		return (0);
	if (ft_read_flags(format, arg) == NULL)
		return (-1);
	if (ft_read_width(format, args, arg) == NULL)
		return (-1);
	if (ft_read_precision(format, args, arg) == NULL)
		return (-1);
	if (ft_read_length(format, arg) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (ft_getter(**format) == NULL)
		getter = ft_get_null;
	else
		getter = ft_getter(**format);
	ret = getter(format, args, arg);
	(*format)++;
	return (ret);
}

static int		ft_printf_fd(const char *format,
		va_list *args, size_t chrs)
{
	char	*next_arg;
	t_arg	arg;
	ssize_t	get_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (chrs);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (chrs + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_printf_fd(next_arg, args, chrs + (next_arg - format)));
	}
	else
	{
		ft_bzero(&arg, sizeof(arg));
		if ((get_len = ft_get_arg((char**)&format, args, &arg)) == -1)
			return (-1);
		else
			return (ft_printf_fd(format, args, (chrs + get_len)));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_printf_fd(format, &arg, 0);
	va_end(arg);
	return (ret);
}
