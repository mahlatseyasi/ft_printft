/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:08:03 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:40:57 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FUNCS_H
# define HANDLE_FUNCS_H
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>

typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			length;
}				t_arg;

typedef ssize_t		(*t_handler)(char**, va_list*, t_arg*);
t_handler			ft_printf_get_handler(char c);
ssize_t				ft_printf_handle_str(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_wstr(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_int(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_long(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_hex(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_octal(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_char(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_wchar(char **format, va_list *args, t_arg *arg);
ssize_t				ft_printf_handle_uint(uintmax_t nbr, t_arg *arg, char *base, char *prefix);


#endif
