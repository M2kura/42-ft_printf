NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ := $(SRC:%.c=%.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -o $@ -c $?

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	mv libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
