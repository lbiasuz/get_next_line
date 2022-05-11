# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 20:44:19 by lbiasuz           #+#    #+#              #
#    Updated: 2022/05/10 23:58:28 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3

SRC		=	get_next_line_utils.c get_next_line.c

OBJ		=	gnl.out

BS		=	42

gnl:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BS) $(SRC) -o $(OBJ)

clean:
	rm -f main.c

fclean: clean
	rm -f gnl.out

test:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BS) $(SRC) main.c -o $(OBJ)
	./$(OBJ)

re: fclean gnl

.PHONY: gnl clean fclean re