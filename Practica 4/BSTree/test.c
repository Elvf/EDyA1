#include <stdio.h>
#include "bstree.h"

static void imprimir_entero(int a) {
  printf("%d ", a);
}

int main(int argc, char *argv[]) {
  BSTree root = NULL;
  
  root = bstree_insertar(root, 1);
  root = bstree_insertar(root, 2);
  root = bstree_insertar(root, 3);
  root = bstree_insertar(root, 4);
  root = bstree_insertar(root, 5);
  
  bstree_recorrer(root, BTREE_RECORRIDO_PRE, imprimir_entero);
  puts("");
  
  root = bstree_balancear(root);
  
  bstree_recorrer(root, BTREE_RECORRIDO_PRE, imprimir_entero);
  puts("");
  /*
  root = bstree_eliminar(root, 3);
  root = bstree_eliminar(root, 1);
  
  bstree_recorrer(root, BTREE_RECORRIDO_IN, imprimir_entero);
  puts("");
  
  printf("Contiene 6: %d\n", bstree_contiene(root, 6));
  printf("Contiene 42: %d\n", bstree_contiene(root, 42));
  
  printf("Elementos: %d\n", bstree_nelems(root));
  printf("Altura: %d\n", bstree_altura(root));
  
  bstree_imprimir(root);
  */
  return 0;
}
