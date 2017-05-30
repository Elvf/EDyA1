#ifndef __CBTREE_H__
#define __CBTREE_H__

/**
 * Ejercicio 8
 * Implementacion de arboles binarios completos con arreglos
 */

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _CBTree {
  int *datos;
  size_t nelems;
  size_t maxElems;
} *CBTree;

CBTree cbtree_crear(size_t levels);

void cbtree_destruir(CBTree arbol);

void cbtree_insertar(CBTree arbol, int dato);

size_t cbtree_nelems(CBTree arbol);

void cbtree_recorrer(CBTree arbol, BTreeOrdenDeRecorrido recorrido, 
                     FuncionVisitante visitar);

void cbtree_recorrer_bfs(CBTree arbol, FuncionVisitante visitar);

#endif /* __CBTREE_H__ */
