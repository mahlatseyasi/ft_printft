# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 17:50:59 by mkhoza            #+#    #+#              #
#    Updated: 2018/08/22 12:01:44 by mkhoza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = calc_nbrstrlen.c ft_printf.c get_handler_arr.c handle_hex.c handle_char.c \
	handle_int.c handle_long.c handle_octal.c handle_str.c handle_unsigned2.c \
	handle_wchar.c handle_wstr.c nbrforceprefix.c parse_handlers.c unsigned_length.c \
	width_pad.c nbrlen.c
		

OUTPUT = calc_nbrstrlen.o ft_printf.o get_handler_arr.o handle_hex.o handle_char.o \
	handle_int.o handle_long.o handle_octal.o handle_str.o handle_unsigned2.o \
	handle_wchar.o handle_wstr.o nbrforceprefix.o parse_handlers.o unsigned_length.o \
	width_pad.o nbrlen.o

$(NAME):
	make -C libft/ 
	gcc $(CFLAGS) -c $(SRC) -I ./ 
	ar -rc $(NAME) $(OUTPUT) ./libft/*.o
	make fclean -C libft/
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
