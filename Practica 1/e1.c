#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort (float arr[], size_t n) {
  int i = 0, j = 0;
  float aux;
  
  for (;i < n - 1; i++) {
    for (; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
      }
    }
  }
}

void printFloatArray (float arr[], size_t n) {
  int i = 0;
  
  for(; i < n; i++) {
    printf("[%f]\t", arr[i]);
  }
  
  printf("\n");
}

float median (float *arr, size_t n) {
  float *copy;
  float medianV;
  
  copy = malloc(n * sizeof(float));
  memcpy(copy, arr, n * sizeof(float));
  
  bubble_sort(copy, n);
  
  //printFloatArray(copy, n);
  
  if ((n % 2) == 0) {
    medianV = (float)((copy[n / 2] + copy[(n / 2) - 1]) / 2);
  } else {
    medianV = copy[(n / 2)];
  }
  
  free(copy);
  
  return medianV;
}

int main (void) {
  float a1[5] = {3.1415, 2.1, 16.33, 14, 0.4};
  float a2[6] = {3.4, 7, 22.33, 31.6, 1.1, 16};
  float medianA1, medianA2;
  
  medianA1 = median(a1, 5);
  medianA2 = median(a2, 6);
  
  printf("Median value for a1: %f\nMedian value for a2: %f\n", medianA1, medianA2);
  
  printFloatArray(a1, 5);
  printFloatArray(a2, 6);
  
  printf("\n");
  
  return 0;
}
