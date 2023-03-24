#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* ptr;
  char ch;

  ptr = fopen("help.doc", "r");
  if(ptr == NULL) {
    printf("The file cannot be open");
    exit(-1);
  }  

  do {
    ch = fgetc(ptr);
    printf("%c", ch);
  }while(ch != EOF);

  fclose(ptr);
  return 0;
}
