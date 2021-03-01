# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbelen <bbelen@21-school.ru>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 16:38:20 by bbelen            #+#    #+#              #
#    Updated: 2020/05/23 15:30:40 by bbelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c\
		./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isprint.c\
		./ft_itoa.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c\
		./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_split.c ./ft_strchr.c ./ft_putstr_fd.c\
		./ft_strdup.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c\
		./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c
BONUS = ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstlast.c\
		./ft_lstnew.c ./ft_lstmap.c ./ft_lstsize.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)
HEADERS = libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
		ar -rsc $(NAME) $(OBJS)

bonus: all $(BOBJS) $(HEADERS)
		ar -rsc $(NAME) $(BOBJS)

%.o:%.c
		gcc $(FLAGS) -o $@ -c $<

clean: 
		rm -f $(BOBJS) $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re