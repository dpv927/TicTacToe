CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = board.o search.o utils.o main.o
DEPS = board.h constants.h search.h utils.h

all: ttt

ttt: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) ttt

