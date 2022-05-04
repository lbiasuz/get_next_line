# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 20:44:19 by lbiasuz           #+#    #+#              #
#    Updated: 2022/05/03 21:55:40 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3

SRC		=	get_next_line.c get_next_line_utils.c

OBJ		=	gnl.out

gnl:
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

clean:
	rm -f main.c

fclean: clean
	rm -f gnl.out

re: fclean gnl

.PHONY: gnl clean fclean re