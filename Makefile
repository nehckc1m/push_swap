NAME = push_swap
CC = cc
SRCS =		srcs/main.c \
		srcs/free.c \
		srcs/check_sort.c \
		srcs/sort.c \
		srcs/initialization.c \
		srcs/utils.c \
		srcs/utils2.c \
		ops/push.c \
		ops/rotates.c \
		ops/swaps.c \
		srcs/ft_atol.c \
		srcs/radix.c \

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
OBJECTS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -L./libft -lft

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) $(FT_PRINTF) $(LIBFT) -o $(NAME) $(LFLAGS)

$(FT_PRINTF):
	make -C ./ft_printf

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./libft
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re

