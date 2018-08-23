/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handler_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:54:55 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:12:34 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	setup_arr(t_getter *getters)
{
	getters['s'] = &ft_get_str;
	getters['S'] = &ft_get_wstr;
	getters['d'] = &ft_get_int;
	getters['i'] = &ft_get_int;
	getters['c'] = &ft_get_char;
	getters['C'] = &ft_get_wchar;
	getters['D'] = &ft_get_long;
	getters['O'] = &ft_get_long;
	getters['U'] = &ft_get_long;
	getters['x'] = &ft_get_hex;
	getters['X'] = &ft_get_hex;
	getters['o'] = &ft_get_octal;
	getters['%'] = &ft_get_escape;
	getters['p'] = &ft_get_ptr;
	getters['u'] = &ft_get_unsigned;
}

t_getter	ft_getter(char c)
{
	static t_getter	*getters = NULL;

	if (getters == NULL)
	{
		getters = ft_memalloc(sizeof(*getters) * 256);
		if (getters != NULL)
			setup_arr(getters);
	}
	return (getters[(int)c]);
}
