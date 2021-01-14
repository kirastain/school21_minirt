# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 12:42:33 by bbelen            #+#    #+#              #
#    Updated: 2020/10/30 18:47:50 by bbelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CC = gcc
MAKE = make
HEADER := /includes

SRC =  ./srcs/bmp.c \
		./srcs/color_diffuse_utils.c ./srcs/color_diffuse.c \
		./srcs/color.c ./srcs/color2.c \
		./srcs/creating_geom_utils.c ./srcs/creating_geom.c \
		./srcs/creating.c \
		./srcs/equation_utils.c ./srcs/equation.c ./srcs/errors.c \
		./srcs/free.c \
		./srcs/geometry.c ./srcs/hooks.c ./srcs/image.c \
		./srcs/inits_geom.c ./srcs/inits.c \
		./srcs/intersect_geom.c ./srcs/intersect.c \
		./srcs/lighting.c \
		./srcs/main.c  \
		./srcs/raycast.c ./srcs/select.c \
		./srcs/resize_utils.c ./srcs/resize.c \
		./srcs/rotate_utils.c ./srcs/rotate.c \
		./srcs/transform.c \
		./srcs/translate_utils.c ./srcs/translate.c \
		./srcs/validation_utils.c ./srcs/validation.c \
		./srcs/vec.c ./srcs/vec2.c ./srcs/vec3_normals.c \
		./srcs/vec4_matrix.c

OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && $(MAKE) bonus
	@cp libft/libft.a libft.a
	@cd mlx && $(MAKE)
	@cp mlx/libmlx.dylib libmlx.dylib
	@echo pre done
	@$(CC) -o $(NAME) $(FLAGS) $(OBJS) libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit
	@echo minirt compiled

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./mlx
	@echo object files deleted

fclean: clean
	@rm -f $(NAME)
	@rm -f minirt.a	
	@rm -f libmlx.dylib
	@rm -f libft.a
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./mlx
	@echo minirt.a deleted

re: fclean all

.PHONY: all clean fclean re