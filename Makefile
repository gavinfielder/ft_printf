# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/03/03 22:11:05 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g
INC=-I libft/includes -I inc
LIB=-L libft/ -lft

SRC=src/api/ft_vsbprintf.c src/api/ft_sbprintf.c src/api/ft_asprintf.c \
	src/backend/ftpf_expandler.c src/backend/ftpf_master.c \
	src/backend/checker_funcs/checker_funcs.c \
	src/backend/expander_funcs/expander_funcs.c

SRC_TEST=src/testing/main.c src/testing/test.c
UNIT_TEST_FILE=src/testing/unit_tests.c
INDEXED_TESTS=src/testing/unit_tests_indexed.c

OBJ:=$(shell echo $(SRC) | sed "s/\.c/\.o/g" | sed "s/src\//bin\//g" | sed "s/api\///g" | sed "s/backend\///g" | sed "s/expander_funcs\///g" | sed "s/checker_funcs\///g")

OBJ_TEST:=$(shell echo $(SRC_TEST) | sed "s/\.c/\.o/g" | sed "s/src\//bin\//g" | sed "s/testing\///g")

all: $(NAME)

$(NAME): bin
	@make -C libft/ > /dev/null 2>&1
	@ar rs $(NAME) $(OBJ) > /dev/null 2>&1
	@echo "Libftprintf compiled."

bin: $(SRC)
	@mkdir -p bin
	@$(CC) -c $(CFLAGS) $(INC) $(SRC)
	@mv *.o bin/

clean:
	@make -C libft/ clean > /dev/null 2>&1
	@rm -rf bin
	@rm -f test_results.txt
	@rm -f $(INDEXED_TESTS)
	@echo "libftprintf: Object files removed."

fclean:
	@make -C libft/ fclean > /dev/null 2>&1
	@rm -rf bin
	@rm -f test_results.txt
	@rm -f $(NAME)
	@rm -f $(INDEXED_TESTS)
	@rm -rf test.dSYM
	@rm -rf test
	@echo "libftprintf: Object files and library removed."

re:
	@make fclean
	@make all

test_index: $(UNIT_TEST_FILE)
	@cp $(UNIT_TEST_FILE) $(INDEXED_TESTS)
	@echo "const t_unit_test g_unit_tests[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*//g" | sed "s/(void)/,/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)

test: $(NAME) $(SRC_TEST) test_index
	@$(CC) $(CFLAGS) $(INC) $(LIB) -o test libftprintf.a $(SRC_TEST) $(INDEXED_TESTS)
