CC=gcc
CFLAGS=-Wall -Wextra -Ofast -march=native -mtune=native
CEXTRAFLAGS=
SRCS=analysis.c board.c heuristic.c main.c move_asker.c parameters.c resources.c search.c sync_game.c argshand.c
OBJS=$(SRCS:.c=.o)
TARGET=ttt

all: $(OBJS)
	$(CC) $(CFLAGS) $(CEXTRAFLAGS) $(OBJS) -o $(TARGET)

%.o: %.
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: clean
