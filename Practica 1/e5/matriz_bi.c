#include <stdio.h>
#include <assert.h>
#include "matriz.h"

/**
 * Implementation using a bidimensional array
 */

struct Matriz_ {
  size_t nRow, nCol;
  double **data;
};


Matriz* matriz_crear(size_t wantRow, size_t wantCol) {
  Matriz* mat = malloc(sizeof(Matriz));
  int i;
  
  /* Fill the colmns and the rows */
  mat->nRow = wantRow;
  mat->nCol = wantCol;
  
  /* Now we need to request memory for the rows, which will house
   * pointers, that determine the columns */
  mat->data = malloc(sizeof(double *) * wantRow);
  
  /* More memory requests for the columns, so we can store the data
   * and access the bidimentional array as arrName[k][l] */
  for (i = 0; i < wantRow; i++) {
    mat->data[i] = malloc(sizeof(double) * wantCol);
  }
  
  return mat;
}

void matriz_destruir(Matriz* mat) {
  int i;
  
  for (i = 0; i < mat->nRow; i++) {
    free(mat->data[i]);
  }
  
  free(mat);
}

double matriz_leer(Matriz* mat, size_t row, size_t col) {
  if (row >= mat->nRow || col >= mat->nCol) {
    printf("ERROR: invalid column or row numbers.\n");
    return -1;
  }
  
  return mat->data[row][col];
}

void matriz_escribir(Matriz* mat, size_t row, size_t col, double val) {
  if (row >= mat->nRow || col >= mat->nCol) {
    printf("ERROR: invalid column or row numbers.\n");
    return;
  }
  
  mat->data[row][col] = val;
}

size_t matriz_num_filas(Matriz* mat) {
  
}

size_t matriz_num_columnas(Matriz* mat) {

}

void matriz_intercambiar_filas(Matriz* mat, size_t rowI, size_t rowJ) {
  int i;
  float aux;
  
  if (rowI >= mat->nRow || rowJ >= mat->nRow) {
    printf("ERROR: invalid row numbers (greater than max rows for matrix)");
    return;
  }
  
  for (i = 0; i < mat->nCol; i++) {
    aux = mat->data[rowI][i];
    mat->data[rowI][i] = mat->data[rowJ][i];
    mat->data[rowJ][i] = aux;
  }
}

Matriz* matriz_insertar_fila(Matriz* mat, float arr[], size_t arraySize, size_t insertAt) {
  Matriz* newMatrix;
  int i, j, alreadyInserted = 0;
  
  if (arraySize != mat->nCol) {
    printf("ERROR: invalid row array size");
    return mat;
  }
  
  /* We make the new matrix which will house the extra row */
  newMatrix = matriz_crear(mat->nRow + 1, mat->nCol);
  
  for (i = 0; i < newMatrix->nRow; i++) {
    if (i == insertAt) {
      for (j = 0; j < newMatrix->nCol; j++) {
        newMatrix->data[i][j] = arr[j];
      }
      alreadyInserted = 1;
    } else {
      if (alreadyInserted == 0) {
        for (j = 0; j < newMatrix->nCol; j++) {
          newMatrix->data[i][j] = mat->data[i][j];
        }
      } else {
        for (j = 0; j < newMatrix->nCol; j++) {
          newMatrix->data[i][j] = mat->data[i - 1][j];
        }
      }
    }
  }
  
  return newMatrix;
}

void matriz_imprimir(Matriz* mat) {
  int i, j;
  
  for (i = 0; i < mat->nRow; i++) {
    for (j = 0; j < mat->nCol; j++) {
      printf("[%f] ", mat->data[i][j]);
    }
    printf("\n");
  }
}

/**
 * 3x3 example diagram of the memory allocation
 * 
 *    Rows         Columns
 * 0  [d*] -----> [d][d][d]
 * 1  [d*] -----> [d][d][d]
 * 2  [d*] -----> [d][d][d]
 * 
 *                 0  1  2
 */
