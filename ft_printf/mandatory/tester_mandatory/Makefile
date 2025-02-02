# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 23:17:39 by nifromon          #+#    #+#              #
#    Updated: 2025/02/02 12:20:44 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	test

all:	$(NAME)

$(NAME):
		cp ../../libftprintf.a $(NAME)
		gcc main.c $(NAME)
		./a.out

clean:
		rm -rf a.out

fclean: clean
		rm -rf $(NAME)

re: 	fclean
		make all

.PHONY: all clean fclean re

#END