#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parameters.h"

void nError(const int numg) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mInvalid number of arguments (Max = 5, Min = 2, Given = %d)!\nexiting...\n", numg-1);
}

void pError(void) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0mUnrecognized option/s or bad order.\nexiting...\n");
}

void vError(const char* value, const char* parameter) {
  fprintf(stderr, "\033[1;37mttt: \033[1;31mfatal error: \
\033[0m%s: Not a value for the option '%s'.\nexiting...\n", value, parameter);
}

int equals(const char* param1, const char* param2) {
  return !(strcmp(param1, param2));
}
