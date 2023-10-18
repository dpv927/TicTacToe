CC=gcc
CFLAGS=-Wall -Wextra -Ofast -march=native -mtune=native
CEXTRAFLAGS=-funroll-loops -finline-functions -fomit-frame-pointer -falign-loops -falign-labels
SRCS=analysis.c argshand.c board.c heuristic.c main.c move_asker.c resources.c search.c sync_game.c
OBJS=$(SRCS:.c=.o)
TARGET=ttt

# Installation variables
LOCAL_MAN_FILE="../doc/$(TARGET).6"
LOCAL_HELP_FILE="../doc/help.txt"
LOCAL_VERSION_FILE="../doc/version.txt"
TARGET_EXEC_PATH="/usr/bin/$(TARGET)"
TARGET_MAN_PATH="/usr/share/man/man6/$(TARGET).6"
TARGET_FULL_DOC_DIR="/etc/$(TARGET)/doc/"
TARGET_DOC_DIR="/etc/$(TARGET)"

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CEXTRAFLAGS) $(OBJS) -o $(TARGET)

%.o: %.
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(TARGET)

install: clean all
	@echo "Copying the man page..."
	sudo cp -r $(LOCAL_MAN_FILE) $(TARGET_MAN_PATH)
	@echo "Copying the executable to $(TARGET_EXEC_PATH)..."
	sudo cp -r $(TARGET) $(TARGET_EXEC_PATH)
	@echo "Copiying the documentation to $(TARGET_DOC_DIR)..."
	sudo mkdir -p $(TARGET_FULL_DOC_DIR)
	sudo cp -r $(LOCAL_HELP_FILE) $(TARGET_FULL_DOC_DIR)
	sudo cp -r $(LOCAL_VERSION_FILE) $(TARGET_FULL_DOC_DIR)
	@echo "Finished."

uninstall:
	@echo "Removing the man page..."
	sudo rm $(TARGET_MAN_PATH)
	@echo "Removing the executable from /usr/bin/..."
	sudo rm $(TARGET_EXEC_PATH)
	@echo "Removing the documentation..."
	sudo rm -rf $(TARGET_DOC_DIR)
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
	@echo "install 			> Compiles and installs ttt in the system."
	@echo "uninstall			> Removes ttt if it is installed in the system."
	@echo ""
	@echo "Do you have any doubts? See the Makefile."
	@echo ""

.PHONY: clean clean-build help install uninstall
