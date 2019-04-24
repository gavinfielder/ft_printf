# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/03/27 12:06:49 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=clang
CFLAGS=-Wall -Wextra -Werror
INC=-I libft/inc -I inc
LIB=-L libft/ -lft

SRC=src/api/ft_asprintf.c src/api/ft_printf.c src/api/ft_sbprintf.c \
	src/api/ft_snprintf.c src/api/ft_sprintf.c \
	src/api/ft_vdprintf.c src/api/ft_vsbprintf.c \
	src/api/ft_vsnprintf.c src/api/ft_vsprintf.c \
	src/api/ft_vprintf.c \
	src/backend/ftpf_expandler.c src/backend/ftpf_master.c \
	src/backend/checker_funcs/ftpf_checker_funcs_index.c \
	src/backend/checker_funcs/ftpf_checker_funcs_00_04.c \
	src/backend/checker_funcs/ftpf_checker_funcs_05_09.c \
	src/backend/checker_funcs/ftpf_checker_funcs_10_14.c \
	src/backend/checker_funcs/ftpf_checker_funcs_15_19.c \
	src/backend/checker_funcs/ftpf_checker_funcs_20_24.c \
	src/backend/checker_funcs/ftpf_checker_funcs_25_29.c \
	src/backend/expander_funcs/ftpf_percent_expander.c \
	src/backend/expander_funcs/ftpf_signed_int_expander.c \
	src/backend/expander_funcs/ftpf_unsigned_int_expander.c \
	src/backend/expander_funcs/ftpf_string_expander.c \
	src/backend/expander_funcs/ftpf_extension_expander.c \
	src/backend/expander_funcs/ftpf_hexlower_expander.c \
	src/backend/expander_funcs/ftpf_hexupper_expander.c \
	src/backend/expander_funcs/ftpf_octal_expander.c \
	src/backend/expander_funcs/ftpf_char_expander.c \
	src/backend/expander_funcs/ftpf_ptr_expander.c \
	src/backend/expander_funcs/ftpf_float_expander.c \
	src/backend/expander_funcs/ftpf_float_expander_utils.c \
	src/backend/expander_funcs/ftpf_floatl_expander.c \
	src/backend/expander_funcs/ftpf_floatl_expander_utils.c \
	src/backend/expander_funcs/ftpf_memory_and_binary_utils.c \
	src/backend/expander_funcs/ftpf_memory_expander.c \
	src/backend/expander_funcs/ftpf_binary_expander.c \
	src/backend/expander_funcs/ftpf_flt_expander_special.c \
	src/backend/getarg_funcs/ftpf_getarg_ints.c \
	src/backend/getarg_funcs/ftpf_getarg_main.c \
	src/backend/getarg_funcs/ftpf_getarg_other.c

OBJ:=$(shell echo $(SRC) | sed "s/\.c/\.o/g" | sed "s/src\//bin\//g" | sed "s/api\///g" | sed "s/backend\///g" | sed "s/expander_funcs\///g" | sed "s/checker_funcs\///g" | sed "s/getarg_funcs\///g")

all: $(NAME)

$(NAME): bin
	@make -C libft/ > /dev/null 2>&1
	@ar rs $(NAME) $(OBJ) libft/bin/*.o > /dev/null 2>&1
	@echo "Libftprintf compiled."

bin: $(SRC)
	@mkdir -p bin
	@$(CC) -c $(CFLAGS) $(INC) $(SRC)
	@mv *.o bin/

clean:
	@make -C libft/ clean > /dev/null 2>&1
	@rm -rf bin
	@echo "libftprintf: Object files removed."

fclean:
	@make -C libft/ fclean > /dev/null 2>&1
	@rm -rf bin
	@rm -f $(NAME)
	@echo "libftprintf: Object files and library removed."

re:
	@make fclean
	@make all
