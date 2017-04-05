#include <stdio.h>
#include <stdlib.h>

int apply (int (*f)(int), int a) {
  return (*f)(a);
}

int sumTwo (int a) {
  return a + 2;
}

int main (int argc, char *argv[]) {
  int a = 2, result;
  
  result = apply(&sumTwo, a);
  
  printf("Result: %d\n", result);
  
  return 0;
}
