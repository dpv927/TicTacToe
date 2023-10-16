#include <stdio.h>
#include <string.h>
#include "argshand.h"

char* GetArg(char const *str_to_find, int narg, char **arg) {
  for(short i=0;i<narg;i++)                
    if (!strcmp(arg[i], str_to_find)) 
      return arg[i+1];          
  return NULL;           
}

int ExistArg(char const *str_to_find, int narg, char **arg) {
  for(short i=0;i<narg;i++)
    if (!strcmp(arg[i], str_to_find)) 
      return i;
  return 0;
}
