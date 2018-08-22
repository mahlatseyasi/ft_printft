/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handler_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:54:55 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:13:09 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "libft/libft.h"
#include "parse_handlers.h"
#include "utils.h"

static void setup_arr(t_handler *handlers)
{
	handlers['s'] = &ft_printf_handle_str;
	handlers['S'] = &ft_printf_handle_wstr;
	handlers['d'] = &ft_printf_handle_int;
	handlers['i'] = &ft_printf_handle_int;
	handlers['c'] = &ft_printf_handle_char;
	handlers['C'] = &ft_printf_handle_wchar;
	handlers['D'] = &ft_printf_handle_long;
	handlers['O'] = &ft_printf_handle_long;
	handlers['U'] = &ft_printf_handle_long;
	handlers['x'] = &ft_printf_handle_hex;
	handlers['X'] = &ft_printf_handle_hex;
	handlers['o'] = &ft_printf_handle_octal;
}

t_handler	ft_printf_get_handler(char c)
{
	static t_handler	*handlers = NULL;

	if (handlers == NULL)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 200);
		if (handlers != NULL)
			setup_arr(handlers);
	}
	return (handlers[(int)c]);
}
