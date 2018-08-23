# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 17:50:59 by mkhoza            #+#    #+#              #
#    Updated: 2018/08/23 14:02:04 by mkhoza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_get_len.c ft_printf.c ft_get_arr.c ft_get_nums.c ft_get_chars.c \
	ft_get_int.c ft_get_spe.c ft_get_unsigned.c ft_get_strs.c  ft_readers.c \
	

OUTPUT = ft_get_len.o ft_printf.o ft_get_arr.o ft_get_nums.o ft_get_chars.o \
	ft_get_int.o ft_get_spe.o ft_get_unsigned.o ft_get_strs.o  ft_readers.o \

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
