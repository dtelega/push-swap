#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 18:42:49 by dtelega           #+#    #+#              #
#    Updated: 2017/03/02 16:12:25 by dtelega          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
NAME_C = checker

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./p_s/
SRC_NAME = main.c revert.c del_first_int.c sort.c get_debug.c

OBJ = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
SRC = $($(SRC_PATH)/$(SRC_NAME))
CPPFLAGS = -I ./p_s/ -I ./libft

SRC_PATH_C = ./check/
SRC_NAME_C = main.c commans_1.c commans_2.c get_next_line.c

OBJ_C = $(SRC_NAME_C:.c=.o)
SRC_C = $($(SRC_PATH_C)/$(SRC_NAME_C))
CPPFLAGS_C = -I ./check/ -I ./libft/

LIBFT = -L ./libft/ -lft

all: $(NAME) $(NAME_C)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $(CPPFLAGS) -o $@ $(OBJ) $(LIBFT)
$(NAME_C): $(OBJ_C)
	@gcc $(FLAGS) $(CPPFLAGS) -o $@ $(OBJ_C) $(LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(COOFLAGS) -o $@ -c $<
$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	@mkdir $(OBJ_PATH_C) 2> /dev/null || true
	@gcc $(FLAGS) $(COOFLAGS_C) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rm -f $(OBJ_C)
	@rmdir $(OBJ_PATH_C) 2> /dev/null || true

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME) $(NAME_C)

re: fclean all
	@make -C libft/ re