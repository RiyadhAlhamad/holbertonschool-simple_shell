CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -pedantic
SRC	= main.c read_line.c parse_line.c
OBJ	= $(SRC:.c=.o)
NAME	= hsh

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
