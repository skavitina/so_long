# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 01:40:50 by tpeggie           #+#    #+#              #
#    Updated: 2022/06/23 23:40:18 by tpeggie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = end_program.c enemy_behaviour.c enemy_generator.c game_init.c\
	get_next_line.c get_next_line_utils.c input.c map_checker_utils.c\
	map_checker.c map_reader.c open_images.c player_movement.c\
	reset.c tilemap_generator.c update.c open_wall_images.c render.c main.c 

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

OBJ			= $(SRC:%.c=%.o)

D			= $(SRC:%.c=%.d)

CC			= gcc

FLAGS = -Wall -Wextra -Werror -MD 
INCLUDE = -lmlx -framework OpenGL -framework AppKit

all: libmake $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	
libmake :
	make -C $(LIBF_DIR)

%.o		:	%.c
	$(CC) $(FLAGS) -c $< -o $@


include 			$(wildcard $(D))

clean:
	@rm -rf $(OBJ) 
	@make -C $(LIBF_DIR) clean

fclean: clean
	@rm -rf $(NAME) $(D)
	@make -C $(LIBF_DIR) fclean

re: fclean all

.PHONY:			all clean fclean re