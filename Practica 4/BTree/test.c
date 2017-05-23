#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static void imprimir_entero(int data) {
  printf("%d ", data);
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);
  int suma, nodos, niveles;

  btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero);
  puts("");
  
  suma = btree_sum(raiz);
  printf("Suma: %d\n\n", suma);
  
  nodos = btree_nodos(raiz);
  printf("Nodos: %d\n\n", nodos);
  
  niveles = btree_altura(raiz);
  printf("Altura: %d\n\n", niveles);
  
  suma = btree_sum_extra(raiz);
  printf("Suma Extra: %d\n\n", suma);
  
  nodos = btree_nodos_extra(raiz);
  printf("Nodos Extra: %d\n\n", nodos);
  
  btree_recorrer_bfs(raiz, imprimir_entero);
  
  btree_destruir(raiz);

  return 0;
}
