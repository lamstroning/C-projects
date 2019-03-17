# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: -tdontos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:58:40 by tdontos-          #+#    #+#              #
#    Updated: 2019/01/06 13:54:10 by tdontos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tdontos-.filler

SRC = filler.c measure_tokn.c check_tokn.c
LIBFT = ./libft
OBJ = $(SRC:.c=.o)
INC = ./
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc  -I$(INC) -c $(SRC)
	@gcc $(OBJ) -L $(LIBFT) -lft -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all