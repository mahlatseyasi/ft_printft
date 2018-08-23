/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:55:14 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:30:25 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <inttypes.h>
# include <stdlib.h>

typedef struct		s_arg
{
	int				push_pref : 1;
	int				pad_zero : 1;
	int				right_pad : 1;
	int				push_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_prec : 1;
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

typedef ssize_t		(*t_getter)(char**, va_list*, t_arg*);
t_getter			ft_getter(char c);
ssize_t				ft_get_str(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_wstr(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_int(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_long(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_hex(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_octal(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_char(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_wchar(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_uint(uintmax_t nbr, t_arg *arg, char *base, char *prefix);
ssize_t				ft_get_escape(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_ptr(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_unsigned(char **format, va_list *args, t_arg *arg);
ssize_t				ft_get_null(char **format, va_list *args, t_arg *arg);
int					ft_printf(const char *format, ...);
char				*ft_read_flags(char **format, t_arg *arg);
char				*ft_read_width(char **format, va_list *list, t_arg *arg);
char				*ft_read_precision(char **format, va_list *list, t_arg *arg);
char				*ft_read_length(char **format, t_arg *arg);
ssize_t				ft_printf_nbrforceprefix(uintmax_t nbr, char *base, t_arg *arg, char *prefix);
unsigned int		ft_nbrstrlen(uintmax_t nbr, char *base, char *prefix, t_arg *arg);
unsigned int		ft_nbrlen(uintmax_t nbr, char *base);
uintmax_t			ft_printf_get_unsigned_from_length(va_list *args, t_arg *arg);


#endif
