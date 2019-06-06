# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:31:12 by yhliboch          #+#    #+#              #
#    Updated: 2019/02/14 14:31:13 by yhliboch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRC_DIR := ./src/
OBJ_DIR := ./obj/
LIB_DIR := ./lib/
INK_DIR := ./ink/
MLX_DIR := ./minilibx_macos/

SRC := main.c map.c draw.c options.c rotation.c zoom_move.c iso.c color.c valid.c parallel.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INK := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

MLX := $(MLX_DIR)libmlx.a
INK_MLX := $(MLX_DIR)
MLX_FLAGS := -lmlx -L $(MLX_DIR)
FRAM := -framework OpenGL -framework AppKit


FLAGS := -Wall -Wextra -Werror
LINK_FLAGS := $(MLX_FLAGS) $(LIBFT_FLAGS)
HEADER_FLAGS := -I $(INK_DIR) -I $(LIBFT_INK) -I $(INK_MLX)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) $(LINK_FLAGS) $(FRAM) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)