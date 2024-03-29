# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2024/03/20 15:40:02 by rraffi-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCDIR = ./src

INCDIR = ./include/

OBJ_DIR = ./build

SRC_NAME =	main.c \
			bonus/bonus_utils_door.c \
			bonus/raycast_sprite_sort.c \
			bonus/raycast_sprite_init.c \
			bonus/raycast_sprite.c \
			bonus/sprite_init.c \
			bonus/minimap.c \
			error_handling.c \
			parsing/spacehandler.c \
			parsing/parse_player_info.c \
			parsing/check_data_validity.c \
			parsing/safe_fd_functions.c \
			parsing/main_parsing.c \
			parsing/get_textures.c \
			parsing/check_map_walls_utils.c \
			parsing/parsing_utils.c \
			parsing/fill_and_check_map.c \
			parsing/parse_rgb.c \
			parsing/struct_utils.c \
			parsing/ft_import.c \
			parsing/check_map_walls.c \
			parsing/check_map_island.c \
			parsing/init_data.c \
			parsing/utils.c \
			parsing/get_file_content.c \
			parsing/parsing_free.c \
			render/hooks.c \
			render/raycast_wall.c \
			render/exit.c \
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

CC = cc -g3

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
