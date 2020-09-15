# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 12:42:33 by bbelen            #+#    #+#              #
#    Updated: 2020/09/12 15:55:08 by bbelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CC = gcc
MAKE = make
HEADER = ft_minirt.h

SRC = ./srcs/color.c ./srcs/color_add.c ./srcs/hooks.c ./main.c \
		./srcs/validation.c ./srcs/creating.c ./srcs/creating_geom.c ./src/raycast.c ./srcs/add_math.c \
		./srcs/intersect.c

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
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./mlx
	@echo minirt.a deleted

re: fclean all

.PHONY: all clean fclean re