/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:46:44 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/02 09:04:41 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"
#include "libft/libft.h"
#include "utils.h"

ssize_t	ft_printf_handle_long(char **format, va_list *args, t_arg *arg)
{
	arg->length = 1;
	return (ft_printf_get_handler(ft_tolower(**format))(format, args, arg));
}
