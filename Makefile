NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra
SOURCES = utils_lst.c parsing.c operations.c operations2.c normalise.c insertion.c \
		  radix.c chunk_base.c insertion_max.c bench.c ft_printf.c utils_printf.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -r $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
