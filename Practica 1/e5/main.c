#include <stdio.h>
#include "matriz.h"

struct Matriz_ {
  size_t nRow, nCol;
  double **data;
};

int main (void) {
  Matriz* m = matriz_crear(3, 3);
  int i, j;
  float rowToInsert[3] = {7, 6, 5};
  
  for (i = 0; i < m->nRow; i++) 
    for (j = 0; j < m->nCol; j++) 
      matriz_escribir(m, i, j, i + j);
      
  printf("%f\n", matriz_leer(m, 2, 1));
  
  matriz_imprimir(m);
  
  matriz_intercambiar_filas(m, 0, 2);
  
  printf("%f\n", matriz_leer(m, 2, 1));
  
  matriz_imprimir(m);
  
  printf("\n");
  
  m = matriz_insertar_fila(m, rowToInsert, 3, 2);
  
  matriz_imprimir(m);
  
  /* Destroy the matrix we created so the memory can be free! */
  matriz_destruir(m);
  
  return 0;
}
