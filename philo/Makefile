SRC = main.c memory.c
NAME = philo
CFLAGS = -Wall -Wextra -Werror
CC = cc 
INCLUD = philo.h
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c $(INCLUD)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all