NAME = corewar

CC = gcc
CFLAGS = 
SRC = main2.c vm.c test2.c ../libft/*.c
GRAPHIC = -lmlx -framework OpenGL -framework AppKit

OBJ = *.o

all: $(NAME) clean

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -c
	@$(CC) $(CFLAGS) $(GRAPHIC) $(OBJ) -o $(NAME)

clean:
	rm  $(OBJ)

fclean:
	rm $(NAME)
	rm $(OBJ)

re: fclean all
