NAME = asm

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c ../libft/*.c

OBJ = *.o

all: $(NAME) clean

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -c 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm  $(OBJ)

fclean:
	rm $(NAME)
	rm $(OBJ)

re: fclean all
