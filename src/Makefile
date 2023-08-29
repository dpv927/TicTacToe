CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -Ofast -march=native -mtune=native
CEXTRAFLAGS=-funroll-loops -finline-functions -fomit-frame-pointer -falign-loops -falign-labels
SRCS=parameters.c analysis.c board.c game.c game_asker.c heuristic.c resources.c search.c main.c
OBJS=$(SRCS:.c=.o)
MAN=../doc/ttt.6
TARGET=ttt

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Compiling the source files: $(SRCS)"
	@echo "Executable Target: $(TARGET)"
	$(CC) $(CFLAGS) $(CEXTRAFLAGS) $(OBJS) -o $(TARGET)
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

install: all
	@echo "Copying the man page..."
	sudo cp -r $(MAN) /usr/share/man/man6/
	@echo "Copying the executable to /usr/bin/..."
	sudo cp -r $(TARGET) /usr/bin/
	@echo "Copiying the documentation to /etc/ttt..."
	sudo mkdir -p /etc/ttt/doc/
	sudo cp -r ../doc/help.txt /etc/ttt/doc/
	sudo cp -r ../doc/version.txt /etc/ttt/doc/
	@echo "Finished."

uninstall:
	@echo "Removing the man page..."
	sudo rm /usr/share/man/man6/ttt.6
	@echo "Removing the executable from /usr/bin/..."
	sudo rm /usr/bin/$(TARGET)
	@echo "Removing the documentation..."
	rm -rf /etc/ttt/
	@echo "Finished."

help:
	@echo ""
	@echo "To compile $(TARGET), type: "
	@echo "make [OPT=option]"
	@echo ""
	@echo "Supported options:"
	@echo ""
	@echo "help 				> Display this message."
	@echo "all 				> Only compile."
	@echo "clean 				> Clean the Makefile directory from old files."
	@echo "clean-build 			> Clean and complile."
	@echo "install 			> Install executable."
	@echo ""
	@echo "Do you have any doubts? See the Makefile."
	@echo ""

.PHONY: clean clean-build help install uninstall
