CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99 -O3 -march=native -mtune=native

SRCS=ai-asker.c board.c game.c player-asker.c resources.c search.c ttt.c
OBJS=$(SRCS:.c=.o)
TARGET=ttt

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Compiling the source files: $(SRCS)"
	@echo "Executable Target: $(TARGET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo "Finished."

%.o: %.
	@echo "Compiling .o files..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning old files..."
	@echo "Targets: $(OBJS) $(TARGET)"
	rm -f $(OBJS) $(TARGET)
	@echo "Finished."

clean-build:
	clean all

help:
	@echo ""
	@echo "To compile $(TARGET), type: "
	@echo "make [OPT=option]"
	@echo ""
	@echo "Supported options:"
	@echo ""
	@echo "help                    > Display this message."
	@echo "all					   > Only compile."
	@echo "clean		           > Clean the Makefile directory from old files."
	@echo "clean-build			   > Clean and complile."
	@echo "install                 > Install executable."
	@echo ""
	@echo "Do you have any doubts? See the Makefile."
	@echo ""

.PHONY: clean clean-build help