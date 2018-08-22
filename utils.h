/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:51:33 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:41:42 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <inttypes.h>
# include <stdint.h>
# include "handle_funcs.h"
# include <sys/types.h>
# include <stdlib.h>

void			ft_printf_width_pad(int len, int width, char padwidth);
ssize_t			ft_printf_nbrforceprefix(uintmax_t nbr, char *base, t_arg *arg, char *prefix);
unsigned int	ft_printf_calc_nbrstrlen(uintmax_t nbr, char *base, char *prefix, t_arg *arg);
unsigned int	ft_printf_nbrlen(uintmax_t nbr, char *base);
uintmax_t		ft_printf_get_unsigned_from_length(va_list *args, t_arg *arg);

#endif
