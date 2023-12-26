# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 21:59:57 by vdecleir          #+#    #+#              #
#    Updated: 2023/12/24 15:39:13 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

CC =		cc

RM =		rm -rf

CFLAGS =	-Wall -Wextra -Werror

MLXFLAGS =	-L. -lmlx -framework OpenGL -framework AppKit

SRCS =		srcs/gnl/get_next_line.c \
			srcs/gnl/get_next_line_utils.c \
			srcs/map_check.c \
			srcs/render_map.c \
			srcs/main.c \
			srcs/utils.c \
			srcs/hooks.c \
			srcs/anim.c \

OBJS = 		$(SRCS:.c=.o)

#FT_PRINTF		= libftprintf.a

#FT_PRINTF_PATH	= ./ft_printf

MLX				= libmlx.a

MLX_PATH		= ./mlx
	
all:		$(NAME)


%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(MLX)
			$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME) $(MLX)

#$(FT_PRINTF):
#			$(MAKE) -C $(FT_PRINTF_PATH)
#			mv $(FT_PRINTF_PATH)/$(FT_PRINTF) .

$(MLX):
			$(MAKE) -C $(MLX_PATH)
			mv $(MLX_PATH)/$(MLX) .

clean:
			$(MAKE) clean -C $(MLX_PATH)
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME) $(MLX)

re: 		fclean all

.PHONY:     all clean fclean re