#include <stdio.h>
#include <stdlib.h>

void printdoc(const char* path) {
  FILE *fptr;
  char c;

  fptr = fopen(path, "r");
  if(fptr == NULL) {
    exit(0);
  }

  c = fgetc(fptr);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(fptr);
  }
  fclose(fptr);
}
