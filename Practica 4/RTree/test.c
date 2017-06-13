#include <stdio.h>
#include "rtree.h"

static void imprimir_entero(void *data) {
  printf("%d ", *((int *)data));
}

static void imprimir_char(void *data) {
  printf("%c", *((char *)data));
}

int main(int argc, char *argv[]) {
  RTree arbolito = rtree_crear();
  /*
  arbolito = rtree_agregar(arbolito, (void *) 4);
  arbolito = rtree_agregar(arbolito, (void *) 2);
  arbolito = rtree_agregar(arbolito, (void *) 1);
  arbolito = rtree_agregar(arbolito, (void *) 5);
  arbolito->hijos->dato = rtree_agregar(arbolito->hijos->dato, (void *) 3);
  
  rtree_recorrer(arbolito, imprimir_entero);
  puts("");
  */
  
  arbolito = rtree_agregar(arbolito, (void *) 'l');
  arbolito = rtree_agregar(arbolito, (void *) 'i');
  arbolito = rtree_agregar(arbolito, (void *) 'u');
  arbolito = rtree_agregar(arbolito, (void *) 'x');
  arbolito->hijos->dato = rtree_agregar(arbolito->hijos->dato, (void *) 'n');
  
  rtree_recorrer(arbolito, imprimir_char);
  puts("");
  
  return 0;
}
