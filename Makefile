
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 11:53:32 by ohladkov          #+#    #+#              #
#    Updated: 2023/11/17 17:29:38 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRS_DIR 		=	./src
SRC				=	$(SRS_DIR)/*.c
OBJ				=	$(S_SRC:.c=.o)

# Compiler
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address 

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRS_DIR)/*.o

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re
