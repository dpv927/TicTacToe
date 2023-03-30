#include <stdio.h>
#include <stdlib.h>
#include "resources.h"

void printDoc(char* path) {
  FILE *fptr;
  char c;

  fptr = fopen(filename, "r");
  if(fptr == NULL) {
    exit(0);
  }

  c = fgetc(fptr);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(fptr);
  }

  fclose(fptr);
  return 0;
}
