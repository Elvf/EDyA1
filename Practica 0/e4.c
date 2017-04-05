#include <stdio.h>

void setZeroZero (int arr[]) {
	arr[0] = 0;
}

int main (void) {
	int a[] = {7, 9, 10, 24, 3};
  
  printf("Primer elemento del array: %d\n", a[0]);
  
  setZeroZero(a);
  
  printf("Luego de correr la funcion el primer elemento es: %d\n", a[0]);
  
  return 0;
}

/**
 * Esto se da porque el array es esencialmente un puntero al primer ele-
 * mento del mismo.
 */
