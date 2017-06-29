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

OBJ_PATH = ./obj_c
SRC_PATH = ./src_p_s/
SRC_NAME = main.c \
			revert.c \
			del_first_int.c \
			sort.c \
			get_debug.c \
			sort_int_tab.c \
			valid_arg.c \

OBJ = $(SRC_NAME:.c=.o)
SRC = $($(SRC_PATH)/$(SRC_NAME))
CPPFLAGS = -I ./p_s/ -I ./libft

SRC_PATH_C = ./src_check/
SRC_NAME_C = main_checker.c \
				ft_strjoin_free.c \
				cmd1.c \
				cmd2.c \
				cmd3.c \
				free_all.c \
				get_next_line.c \
				valid_arg_c.c

OBJ_C = $(SRC_NAME_C:.c=.o)
SRC_C = $($(SRC_PATH_C)/$(SRC_NAME_C))
CPPFLAGS_C = -I ./check/ -I ./libft/

LIBFT = -L ./libft/ -lft

all: $(NAME) $(NAME_C)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) $(CPPFLAGS) -o $@ $(OBJ) $(LIBFT)
$(NAME_C): $(OBJ_C)
	gcc $(FLAGS) $(CPPFLAGS_C) -o $@ $(OBJ_C) $(LIBFT)

%.o: $(SRC_PATH)%.c
	gcc $(FLAGS) $(COOFLAGS) -c $< -o $@
%.o: $(SRC_PATH_C)%.c
	gcc $(FLAGS) $(COOFLAGS_C) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	rm -f $(OBJ_C)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME) $(NAME_C)

re: fclean all
	make -C libft/ re