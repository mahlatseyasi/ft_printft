/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:37:31 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:52:04 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_putnbrbp(uintmax_t nbr, char *base,
		t_arg *arg, unsigned int nbr_len)
{
	if (arg->got_prec)
		ft_width_pad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->got_prec && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}

ssize_t		ft_get_uint(uintmax_t nbr, t_arg *arg, char *base, char *prefix)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	if (arg->got_prec)
		arg->pad_zero = 0;
	nbr_len = ft_nbrlen(nbr, base);
	if (arg->got_width && !arg->right_pad && arg->pad_zero)
	{
		if (arg->got_prec)
			arg->precision = ft_maxi(arg->width, arg->precision);
		else
			arg->precision = ft_maxi(arg->width, nbr_len);
		arg->got_prec = 1;
		arg->got_width = 0;
	}
	nbrstrlen = ft_nbrstrlen(nbr, base, prefix, arg);
	if (arg->got_width && !arg->right_pad)
		ft_width_pad(nbrstrlen, arg->width, ' ');
	if (arg->push_pref && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, base, arg, nbr_len);
	if (arg->got_width && arg->right_pad)
		ft_width_pad(nbrstrlen, arg->width, ' ');
	return (arg->got_width ? ft_maxi(nbrstrlen, arg->width) : nbrstrlen);
}

ssize_t		ft_get_unsigned(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	num;

	format = 0;
	num = ft_printf_get_unsigned_from_length(args, arg);
	return (ft_get_uint(num, arg, "0123456789", NULL));
}

uintmax_t	ft_printf_get_unsigned_from_length(va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

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
