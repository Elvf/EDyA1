#include <stdio.h>
#include "cbtree.h"

void imprimir_entero(int a) {
  printf("%d ", a);
}

int main(int argc, char *argv[]) {
  CBTree arbol = cbtree_crear(4);
  
  cbtree_insertar(arbol, 3);
  cbtree_insertar(arbol, 2);
  cbtree_insertar(arbol, 7);
  cbtree_insertar(arbol, 9);
  cbtree_insertar(arbol, 0);
  cbtree_insertar(arbol, 4);
  cbtree_insertar(arbol, 1);
  
  printf("nelems: %lu\n\n", arbol->nelems);
  
  cbtree_recorrer(arbol, BTREE_RECORRIDO_POST, imprimir_entero);
  puts("");
  
  cbtree_recorrer_bfs(arbol, imprimir_entero);
  puts("");
  
  return 0;
}
