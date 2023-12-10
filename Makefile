# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 21:59:57 by vdecleir          #+#    #+#              #
#    Updated: 2023/12/10 22:33:46 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= so_long

CFLAGS 		= -Wall -Wextra -Werror -Imlx

SRCS	 	= so_long.c

INCLUDESDIR	= so_long.h

MY_OBJECTS	= $(SRCS:.c=.o)

RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDESDIR) -c $< -o $@

$(NAME):	$(MY_OBJECTS)
			$(CC) $(MY_OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(NAME)

all:		$(NAME)


clean:
			$(RM) $(MY_OBJECTS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re