# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebitca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/21 19:38:45 by ebitca            #+#    #+#              #
#    Updated: 2016/08/21 19:40:50 by ebitca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc -Wall -Wextra -Werror
NAME = eval_expr
SRC = get.c check.c eval_expr.c f_package.c main.c queue_stack.c -Ift_all.h

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all
