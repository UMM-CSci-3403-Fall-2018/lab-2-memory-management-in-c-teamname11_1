#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  char *disemvoweled_str;
  
  size = 100;
  line = (char*) malloc (size + 1);

  // For each line entered into the console,
  // a variable is used for the call to disemvowel
  // which is subsequently freed after the
  // disemvoweled string is printed
  while (getline(&line, &size, stdin) > 0) {
    disemvoweled_str = disemvowel(line);	
    printf("%s\n", disemvoweled_str);
    free(disemvoweled_str);
  }

  free(line);
}
