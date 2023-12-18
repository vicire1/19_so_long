# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 21:59:57 by vdecleir          #+#    #+#              #
#    Updated: 2023/12/18 17:43:30 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SRCS =		srcs/gnl/get_next_line.c \
			srcs/gnl/get_next_line_utils.c \
			srcs/map_check.c \
			srcs/render_map.c \
			srcs/so_long.c \
			srcs/utils.c

OBJS = 		$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean: 	clean
			rm -rf $(NAME)

re: 		fclean all

.PHONY:     all clean fclean re