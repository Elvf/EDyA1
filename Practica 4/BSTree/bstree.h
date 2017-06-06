#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);
typedef void (*FuncionArray) (int arr[], int *pos, int elem);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BSNode {
  int dato;
  struct _BSNode *left;
  struct _BSNode *right;
} BSNode;

typedef BSNode *BSTree;

BSTree bstree_insertar(BSTree arbol, int dato);

BSTree bstree_eliminar(BSTree arbol, int dato);

int bstree_contiene(BSTree arbol, int dato);

unsigned int bstree_nelems(BSTree arbol);

unsigned int bstree_altura(BSTree arbol);

void bstree_recorrer(BSTree arbol, BTreeOrdenDeRecorrido orden,
                     FuncionVisitante visitar);

/**
 * Ejercicio 10
 */
void bstree_imprimir(BSTree arbol);

BSTree bstree_balancear(BSTree arbol);

int bstree_minimo(BSTree arbol);

int bstree_acceder(BSTree arbol, int indice);

#endif /* __BSTREE_H__ */
