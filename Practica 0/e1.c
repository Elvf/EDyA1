#include <stdio.h>

int main (void) {
  int a = 42, i;
  float b = 3.141592f;
  char c[17] = "Hello World!";
  
  printf("LOCAL VAR ADDRESSES:\na -> %p\nb -> %p\n", &a, &b);
  
  for (i = 0; i < 17; i++) 
    printf("Char %d: %p\n", i, &c[i]);
  
  return 0;
}
