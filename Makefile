# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 21:59:57 by vdecleir          #+#    #+#              #
#    Updated: 2023/12/28 02:23:10 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L. -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/gnl/get_next_line.c \
       srcs/gnl/get_next_line_utils.c \
       srcs/map_check.c \
       srcs/render_map.c \
       srcs/main.c \
       srcs/utils.c \
       srcs/hooks.c \
       srcs/anim.c \
	   srcs/parsing.c

OBJ_DIR = objets

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

FT_PRINTF = libftprintf.a

MLX_PATH = ./ft_printf

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME) $(FT_PRINTF)
	@echo "\n\033[1;32mCompilation complete.\033[0m"

#$(MLX):
#	$(MAKE) -C $(MLX_PATH)
#	mv $(MLX_PATH)/$(MLX) .

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)
	mv $(FT_PRINTF_PATH)/$(FT_PRINTF) .

clean:
	$(MAKE) clean -C $(FT_PRINTF_PATH)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re