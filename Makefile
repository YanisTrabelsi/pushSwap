NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra
SOURCES = ft_disorder.c utils_lst.c is_duplicate.c ft_atoi.c
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
