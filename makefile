SRC = 	./src/main.c			\
	./src/check_av.c		\
	./src/game.c			\
	./src/my_show_board.c		\
	./src/init.c			\
	./src/my_putstr.c		\
	./src/my_strlen.c		\
	./src/ai.c			\
	./src/input.c			\
	./src/curses.c			\

NAME = TicTacToe

CC = cc -g

OBJ = $(SRC:.c=.o)

RM = rm -rf

all :	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf ./src/*~

re : fclean all
