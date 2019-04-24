# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 14:09:16 by gfielder          #+#    #+#              #
#    Updated: 2019/03/24 16:01:14 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME=libft.a
CC=clang
CFLAGS=-Wall -g -Wextra -Werror -I inc/

SRC=other/ft_get_next_line.c \
other/ft_putstr.c \
other/ft_strcmp.c \
other/ft_mem_1.c \
other/ft_destroy_nullterm_ptrarray.c \
other/ft_strsplit.c \
other/ft_strstr.c \
other/ft_putnbr.c \
other/ft_litoa.c \
other/ft_str_constructors.c \
other/ft_mem_2.c \
other/ft_strcpy.c \
other/ft_putchar.c \
other/ft_itoa.c \
other/ft_str_aux.c \
other/ft_strtrim.c \
other/ft_strcat.c \
other/ft_strjoin.c \
other/ft_atoi.c \
other/ft_print_hex.c \
hat/ft_hat_toarr.c \
hat/ft_hatdellf.c \
hat/ft_hat_aux.c \
hat/ft_hatinslf.c \
hat/ft_hat_backend_1.c \
hat/ft_hat.c \
multistringer/ft_multistringer_aux.c \
multistringer/ft_sbtostr.c \
multistringer/ft_buffwriter.c \
multistringer/ft_stringwriter.c \
multistringer/ft_fildeswriter.c \
multistringer/ft_multistringer.c \
multistringer/ft_mswrite_nullterm.c \
multistringer/ft_stringbuilder.c

OBJ:=$(shell echo $(SRC) | sed "s/\.c/\.o/g" | sed "s/other\//bin\//g" | sed "s/hat\//bin\//g" | sed "s/multistringer\//bin\//g")


all: $(NAME)

$(NAME): bin
	@ar rs $(NAME) $(OBJ) > /dev/null 2>&1
	@echo "Libft compiled."

bin: $(SRC)
	@mkdir -p bin
	@clang -c $(CFLAGS) $(SRC)
	@mv *.o bin

clean:
	@rm -rf bin
	@echo "libft: Object files removed."

fclean:
	@rm -rf bin
	@rm -f libft.a
	@echo "libft: Object files and library removed."

re:
	@make fclean
	@make all
