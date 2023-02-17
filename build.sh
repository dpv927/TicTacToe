#!/bin/bash
# Dont modify the source or executable names at the compilation section.
# Make your changes at the variables declaration.
# Filipondios 16-02-2023

# Define the names of the source code files
MAIN_SOURCE="main.c"

# Define the names of the generated executables
MAIN_EXEC="tic-tac-toe"

# Define the name of the man documentation
MAN_FILE="tic-tac-toe.6"

function cleanf() {
  # Remove old executable files
  rm -rf "$MAIN_EXEC"
}

function generate() {
  # Compile the main program
  gcc "$MAIN_SOURCE" -o "$MAIN_EXEC"
}

function generate-verbose() {
  # Compile the main program with the verbose option
  gcc "$MAIN_SOURCE" -o "$MAIN_EXEC" -v
}

function install() {
  if [ $(id -u) != 0 ]; then
    echo "You must be a superuser to do this action."
    exit -1
  fi
  cp -r "$MAIN_EXEC" /usr/bin/
  cp -r "$MAN_FILE" /usr/share/man/man6/
}

function uninstall() {
  if [ $(id -u) != 0 ]; then
    echo "You must be a superuser to do this action."
    exit -1
  fi
  rm /usr/bin/"$MAIN_EXEC"
  rm /usr/share/man/man6/"$MAN_FILE"
}

# Quick compilation -> No arguments
if [ $# == 0 ]; then
  cleanf
  generate
  exit 0
fi

# Detailed manipulation -> One or more arguments
# Create a list with the args:
args=()

# Get all the valid arguments and if there is a invalid argument,
# then exit the script
for arg in "$@"; do
  case "$arg"  in
    "cleanf" | "install" | "generate" | "uninstall" | "generate-verbose")
      args+=($arg)
      ;;
    *)
      echo "Invalid option: $arg. Exiting..."
      exit -1
      ;;
  esac
done

# Sort the args and remove the repeated args
args=($(echo "${args[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' '))
echo "Executing the following options: ${args[@]}..."

# Exec all args
for arg in "${args[@]}"; do
  $arg
done

echo "Done."
