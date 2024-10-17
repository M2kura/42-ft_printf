NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ := $(SRC:%.c=%.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -o $@ -c $?

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) clean

re: fclean all	