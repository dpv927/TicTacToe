#include "argshand.h"

int main(int argc, char *argv[]) {
  CheckNumberArgs(argc);
  ProcessArguments(argc, argv);
  return 0;
}
