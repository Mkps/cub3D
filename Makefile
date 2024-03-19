# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2024/03/11 14:07:35 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCDIR = ./src

INCDIR = ./include/

OBJ_DIR = ./build

SRC_NAME =	main.c \
			error_handling.c \
			bonus/bonus_utils_door.c \
			bonus/minimap.c \
			parsing/check_data_validity.c \
			parsing/safe_fd_functions.c \
			parsing/main_parsing.c \
			parsing/parsing_utils.c \
			parsing/parse_rgb.c \
			parsing/struct_utils.c \
			parsing/ft_import.c \
			parsing/set_pdir.c \
			parsing/init_data.c \
			parsing/parsing.c \
			parsing/utils.c \
			parsing/main_.c \
			render/hooks.c \
			render/raycast_wall.c \
			render/raycast_sprite_sort.c \
			render/exit.c \
			render/raycast_sprite_init.c \
			render/raycast_sprite.c \
			render/render.c \
			render/img_init.c \
			render/color_utils.c \
			render/player_rotate.c \
			render/raycast_wall_color.c \
			render/raycast_fc.c \
			render/mlx_pixel.c \
			render/draw.c \
			render/destroy.c \
			render/key_input.c \
			render/raycast_wall_init.c \
			render/player_move.c \

SRC = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:c=o))

CC = cc

LIB = -lft -lmlx -lXext -lX11 -lm

$(NAME): CFLAGS = -Wall -Wextra -Werror -DBONUS=0 -I$(INCDIR)
bonus: CFLAGS = -Wall -Wextra -Werror -DBONUS=1 -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling objects for mandatory part"
	@make -s all -C libft
	$(CC) -o $(NAME) -L libft -L minilibx $(OBJ) $(LIB) 

$(OBJ_DIR)/%.o:	$(SRCDIR)/%.c
	@mkdir -p '$(@D)'
	@echo $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

bonus: fclean $(OBJ)
	@echo "Compiling objects for bonus part"
	@make -s all -C libft
	$(CC) -o $(NAME) -L libft -L minilibx $(OBJ) $(LIB) 

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME)
	@make -s fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
