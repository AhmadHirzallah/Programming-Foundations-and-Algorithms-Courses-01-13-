CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRCS = lib/game.c lib/round.c lib/utils.c src/main.c
OBJS = $(SRCS:.c=.o)
EXEC = game

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
