/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrforceprefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:15:00 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:34:01 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils.h"
#include "handle_funcs.h"

ssize_t	ft_printf_nbrforceprefix(uintmax_t nbr, char *base, t_arg *arg,
		char *prefix)
{
	unsigned int	nbr_len;
	size_t			nbr_cut;

	nbr_len = ft_printf_calc_nbrstrlen(nbr, base, NULL, arg) + ft_strlen(prefix);
	nbr_cut = ft_strlen(prefix);
	if (arg->got_width && !arg->right_pad && !arg->pad_zeroes)
	{
		ft_printf_width_pad(nbr_len, arg->width, ' ');
	   nbr_cut += FT_MAX(arg->width	- nbr_len, 0);
	   arg->got_width = 0;
	}
	else if (arg->got_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_printf_handle_uint(nbr, arg, base, NULL) + nbr_cut);
}