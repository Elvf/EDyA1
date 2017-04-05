#include <stdio.h>
#include "matriz.h"

/**
 * Implementation using unidimensional arrays
 */

struct Matriz_ {
  size_t nRow, nCol;
  double *data;
};


Matriz* matriz_crear(size_t wantRow, size_t wantCol) {
  Matriz* mat = malloc(sizeof(Matriz));
  
  /* Set the values for the rows and columns wanted */
  mat->nRow = wantRow;
  mat->nCol = wantCol;
  
  /* Allocate memory for the data */
  mat->data = malloc(sizeof(double) * wantRow * wantCol);
  
  return mat;
}

void matriz_destruir(Matriz* mat) {
  free(mat->data);
  free(mat);
}

double matriz_leer(Matriz* mat, size_t row, size_t col) {
  if (row >= mat->nRow || col >= mat->nCol) {
    printf("ERROR: invalid column or row numbers.\n");
    return -1;
  }
  
  return mat->data[(row * mat->nCol + col)];
}

void matriz_escribir(Matriz* mat, size_t row, size_t col, double val) {
  if (row >= mat->nRow || col >= mat->nCol) {
    printf("ERROR: invalid column or row numbers.\n");
    return;
  }
  
  mat->data[(row * mat->nCol) + col] = val;
}

/**
 * Isn't this just mat->nCol and mat->nRow???
 */
size_t matriz_num_filas(Matriz* mat) {

}

size_t matriz_num_columnas(Matriz* mat) {

}
