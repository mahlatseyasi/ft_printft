/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbrstrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:40:39 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:53:45 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils.h"
#include "handle_funcs.h"

unsigned int	ft_printf_calc_nbrstrlen(uintmax_t nbr, char *base, char *prefix, t_arg *arg)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbrstrlen = 0;
	nbr_len = ft_printf_nbrlen(nbr, base);
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->got_precision)
		nbrstrlen += FT_MAX(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->force_prefix && prefix != NULL &&nbr != 0)
		nbrstrlen += ft_strlen(prefix);
	return (nbrstrlen);
}
