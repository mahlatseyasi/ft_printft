/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:22:21 by mkhoza            #+#    #+#             */
/*   Updated: 2018/07/30 11:33:35 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HANDLERS_H
# define PARSE_HANDLERS_H
# include "handle_funcs.h"

char	*ft_printf_parse_flags(char **format, t_arg *arg);
char	*ft_printf_parse_width(char **format, va_list *list, t_arg *arg);
char	*ft_printf_parse_precision(char **format, va_list *list, t_arg *arg);
char	*ft_printf_parse_length(char **format, t_arg *arg);

#endif
