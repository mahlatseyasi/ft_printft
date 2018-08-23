/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbrstrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:40:39 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:56:20 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

unsigned int	ft_nbrstrlen(uintmax_t nbr,
		char *base, char *prefix, t_arg *arg)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbr_len = ft_nbrlen(nbr, base);
	if (nbr == 0 && arg->got_prec && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->got_prec)
		nbrstrlen = ft_maxi(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->push_pref && prefix != NULL && nbr != 0)
		nbrstrlen += ft_strlen(prefix);
	return (nbrstrlen);
}

unsigned int	ft_nbrlen(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_nbr;
		i++;
	}
	return (i);
}

ssize_t			ft_printf_nbrforceprefix(uintmax_t nbr, char *base, t_arg *arg,
		char *prefix)
{
	unsigned int	nbr_len;
	size_t			nbr_cut;

	nbr_len = ft_nbrstrlen(nbr, base, NULL, arg) + ft_strlen(prefix);
	nbr_cut = ft_strlen(prefix);
	if (arg->got_width && !arg->right_pad && !arg->pad_zero)
	{
		ft_width_pad(nbr_len, arg->width, ' ');
		nbr_cut += ft_maxi(arg->width - nbr_len, 0);
		arg->got_width = 0;
	}
	else if (arg->got_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_get_uint(nbr, arg, base, NULL) + nbr_cut);
}
