#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int* dir;
  size_t capacity;
} IntArray;

/**
 * EX 3
 */
IntArray* createArray (size_t capacity) {
  IntArray* newArray = malloc(sizeof(IntArray));
  
  newArray->dir = malloc(sizeof(int) * capacity);
  newArray->capacity = capacity;
  
  return newArray;
}

void destroyArray (IntArray* arr) {
  free(arr->dir);
  free(arr);
}

int readFromArray (IntArray* arr, size_t pos) {
  if (pos >= arr->capacity) {
    printf("ERROR: The position requested is greater than the max elements in the array");
    return -1;
  }
  
  return arr->dir[pos];
}

void writeToArray (IntArray* arr, size_t pos, int data) {
  if (pos >= arr->capacity) {
    printf("ERROR: The position requested is greater than the max elements in the array");
    return;
  }
  
  arr->dir[pos] = data;
}

size_t arrayCapacity (IntArray* arr) {
  return arr->capacity;
}

void printArray (IntArray arr) {
  int i;
  
  for (i = 0; i < arr.capacity; i++) {
    printf("[%d] ", arr.dir[i]);
  }
  
  printf("\n");
}

/**
 * EX 4
 */
void adjustArray (IntArray* arr, size_t newCapacity) {
  IntArray* copy = malloc(sizeof(IntArray));
  int i;
  
  /* We must copy the array so as to not lose the data with realloc,
   * otherwise we'd wipe the original array */
  copy->dir = malloc(sizeof(int) * arr->capacity);
  copy->capacity = arr->capacity;
  memcpy(copy->dir, arr->dir, sizeof(int) * arr->capacity);
  
  /* No need to realloc if we are asked for the same amount of elemts */
  if (newCapacity == copy->capacity) {
    return;
  }
  
  arr->dir = realloc(arr->dir, newCapacity * sizeof(int));
  
  /* If the new capacity is greater, we can copy all the elements back
   * to the array, but if it's less than the original capacity from the
   * array, we have to truncate it */
  if (newCapacity > copy->capacity) {
    memcpy(arr->dir, copy->dir, copy->capacity * sizeof(int));
    arr->capacity = newCapacity;
  } else {
    for (i = 0; i < newCapacity; i++) {
      arr->dir[i] = copy->dir[i];
    }
    arr->capacity = newCapacity;
  }
  
  destroyArray(copy);
}

void intArrayInsert (IntArray* arr, size_t pos, int data) {
  int i;
  
  if (pos >= arr->capacity) {
    printf("ERROR: The position requested is greater than the max elements in the array");
    return;
  }
  
  adjustArray(arr, arr->capacity + 1);
  
  for (i = arr->capacity - 2; i >= pos; i--) {
    arr->dir[i + 1] = arr->dir[i];
  }
  
  arr->dir[pos] = data;
}

void intArrayDelete (IntArray* arr, size_t pos) {
  int i;
  
  if (pos >= arr->capacity) {
    printf("ERROR: The position requested is greater than the max elements in the array");
    return;
  }
  
  for (i = pos; i < arr->capacity - 2; i++) {
    arr->dir[i] = arr->dir[i + 1];
  }
  
  adjustArray(arr, arr->capacity - 1);
}

/**
 * MAIN FOR TESTING
 */
int main (void) {
  IntArray* test = createArray(5);
  int i, secondElement;
  
  for (i = 0; i < 5; i++) {
    srand(time(NULL) + i);
    writeToArray(test, i, rand() % 80);
  }
  
  secondElement = readFromArray(test, 1);
  
  printf("The 2nd element of the array is: %d\n\n", secondElement);
  
  printf("TEST ARRAY:\n");
  printArray(*test);
  
  adjustArray(test, 7);
  writeToArray(test, 5, 21);
  writeToArray(test, 6, 42);
  
  intArrayInsert(test, 3, 160);
  
  printf("TEST ARRAY:\n");
  printArray(*test);
  
  intArrayDelete(test, 4);
  
  printf("TEST ARRAY:\n");
  printArray(*test);
  
  destroyArray(test);

  return 0;
}
