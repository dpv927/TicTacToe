#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parameters.h"

void nError(const int numg) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mInvalid number of arguments (%d)!\nexiting...\n", numg-1);
  exit(EXIT_FAILURE);
}

void pError(void) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option/s or bad placement.\nexiting...\n");
  exit(EXIT_FAILURE);
}

void vError(const char* value, const char* parameter) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0m%s: Not a value for the option '%s'.\nexiting...\n", value, parameter);
  exit(EXIT_FAILURE);
}

int equals(const char* param1, const char* param2) {
  return !(strcmp(param1, param2));
}
