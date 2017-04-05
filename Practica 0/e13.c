#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int *space = malloc(100);
  
  free(space);
  free(space);
}
