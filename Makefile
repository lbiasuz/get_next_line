# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 20:44:19 by lbiasuz           #+#    #+#              #
#    Updated: 2022/05/18 22:42:24 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3

SRC		=	get_next_line_utils.c new_get_next_line.c

OBJ		=	gnl.out

BS		=	4

gnl:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BS) -c $(SRC) -o $(OBJ)

clean:
	rm -f gnl.out

fclean: clean
	rm -f main.c

test:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BS) $(SRC) main.c -o $(OBJ)

re: clean gnl

.PHONY: gnl clean fclean re