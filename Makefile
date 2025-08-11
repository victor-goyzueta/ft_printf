GREEN	=	\033[1;32m
CYAN	=	\033[1;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	= 	ft_printf.c	\
			utils.c		\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(CLEAR)$(GREEN)libftprintf successfully created."

%.o: %c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(CLEAR)$(CYAN)Compiling $<..."

clean:
	@rm -f $(OBJS)
	@echo "$(CLEAR)$(CYAN)libftprintf: Objetcs files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(CLEAR)$(CYAN)libftprintf: Clean completed, libftprintf.a deleted."

re: fclean all

.PHONY: all clean fclean re
