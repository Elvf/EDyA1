#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stddef.h>

typedef void *FuncionVisitante (int dato);

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

void bstree_recorrer(BSTree arbol, FuncionVisitante visitar);

#endif /* __BSTREE_H__ */
