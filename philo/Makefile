SRC = 		main.c \
			./mem/memory.c \
			./parse/check_numbers_utiles.c \
			./parse/check_numbers.c \
			./src/create_philos.c \
			./src/ft_init.c \
			./src/time.c \
			./src/message.c \
			./src/destroy_mutex.c
NAME = philo
CFLAGS = -Wall -Wextra -Werror -lpthread #-fsanitize=address -g

CC = gcc
INCLUD = ./include/philo.h
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