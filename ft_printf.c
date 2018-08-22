/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:23:19 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 17:50:18 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handle_funcs.h"
#include "parse_handlers.h"
#include "libft/libft.h"

static ssize_t	handle_arg(char **format, va_list *args, t_arg *sarg)
{
	ssize_t		ret;
	t_handler	handler;

	if (*(++*format) == '\0')
		return (0);
	if (ft_printf_parse_flags(format, sarg) == NULL)
		return (-1);
	if (ft_printf_parse_width(format, args, sarg) == NULL)
		return (-1);
	if (ft_printf_parse_precision(format, args, sarg) == NULL)
		return (-1);
	if (ft_printf_parse_length(format, sarg) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	else
		handler = ft_printf_get_handler(**format);
	ret = handler(format, args, sarg);
	(*format)++;
	return (ret);
}

static int				ft_inner_printf(const char *format, va_list *list, size_t chrs)
{
	//Here chrs is set to 0
	char	*next_arg;
	t_arg	sarg;
	ssize_t	handle_len;

	next_arg = ft_strchr(format, '%');
	 if (*format == '\0')
		 return (chrs);
	if (next_arg == NULL)
	{	ft_putstr(format);
		return (chrs + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_inner_printf(next_arg, list, chrs + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));//initializes sarg to zero
		if ((handle_len = handle_arg((char**)&format, list, &sarg)) == - 1)
			return (-1);
		else
			return (ft_inner_printf(format, list, (chrs + handle_len)));
	}
}

/*
 *ft_printf is a variadic function i.e it accepts a variable number of arguments
 */
int		ft_printf(const char *format, ...)
{
	va_list	list;
	int		ret;

	va_start(list, format); //initializes the va_list
	ret = ft_inner_printf(format, &list, 0); 
	va_end(list); //clean the the memory assigned to args
	return (ret);
}
