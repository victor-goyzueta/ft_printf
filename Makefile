# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 21:20:14 by vgoyzuet          #+#    #+#              #
#    Updated: 2024/11/06 16:57:35 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c\
	utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libftprintf successfully created."

%.o: %c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Copiling $<..."

clean:
	@rm -f $(OBJS)
	@echo "Objetcs files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "Clean completed, libftpriintf.a deleted."

re: fclean all

.PHONY: all clean fclean re
