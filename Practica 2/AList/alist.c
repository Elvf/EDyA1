#include <stdio.h>
#include <stdlib.h>
#include "alist.h"

AList alist_crear(void) {
  AList nuevaLista = malloc(sizeof(_AList));
  
  /* Inicializamos la nueva lista con 4 enteros, si necesitamos
   * mas espacio haremos un realloc despues */
  nuevaLista->datos = malloc(4 * sizeof(int));
  nuevaLista->ultimo = -1;
  nuevaLista->capacidad = 4;
  
  return nuevaLista;
}

void alist_destruir(AList lista) {
  free(lista->datos);
  free(lista);
}

int alist_vacia(AList lista) {
  return (lista->ultimo == -1);
}

void alist_agregar(AList lista, int dato) {
  if ((lista->ultimo + 1) == lista->capacidad) {
    realloc(lista->datos, 2 * lista->capacidad);
    lista->capacidad = lista->capacidad * 2;
  }
  
}
  
