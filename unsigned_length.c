/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 09:20:12 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:32:05 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_funcs.h"

uintmax_t   ft_printf_get_unsigned_from_length(va_list *args, t_arg *arg)
{
    uintmax_t   nbr;

    nbr = va_arg(*args, uintmax_t);
    if (arg->length == hh)
        nbr = (unsigned char)nbr;
    else if (arg->length == h)
        nbr = (unsigned short int)nbr;
    else if (arg->length == l)
        nbr = (unsigned long int)nbr;
    else if (arg->length == ll)
        nbr = (unsigned long long int)nbr;
    else if (arg->length == j)
        nbr = (uintmax_t)nbr;
    else if (arg->length == z)
        nbr = (size_t)nbr;
    else
        nbr = (unsigned int)nbr;
    return (nbr);
}
