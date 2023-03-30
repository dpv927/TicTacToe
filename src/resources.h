/**@brief Prints the content of a documentation file.
 * @param poth Path of the file whe is the documentation. **/
//void printDoc(char* path);

#include <stdio.h>
#include <stdlib.h>

void printdoc(char* path) {
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
