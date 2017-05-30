#include <stdlib.h>
#include <stdio.h>
#include "cbtree.h"

#define padre(x) (x / 2) - 1
#define hijod(x) (x * 2) + 2
#define hijoi(x) (x * 2) + 1

static int dos_a_la(int n) {
  int result = 2;
  
  for(int i = 0; i < n - 1; i++) {
    result = result * 2;
  }
  
  return result;
}

CBTree cbtree_crear(size_t niveles) {
  CBTree newTree = malloc(sizeof(CBTree));
  int elementos = dos_a_la(niveles) - 1;
  
  newTree->datos = malloc(sizeof(int) * elementos);
  newTree->nelems = 0;
  newTree->maxElems = elementos;
  
  return newTree;
}

void cbtree_destruir(CBTree arbol) {
  if (arbol) {
    free(arbol->datos);
    free(arbol);
  } else return;
}

void cbtree_insertar(CBTree arbol, int dato) {
  if (!arbol) return;
  if (arbol->nelems == arbol->maxElems) return;
  
  (arbol->nelems)++;
  arbol->datos[arbol->nelems - 1] = dato;
}

size_t cbtree_nelems(CBTree arbol) {
  if (arbol) return arbol->nelems;
  else return -1;
}

static void aux_in(int *datos, int indiceActual, size_t max, FuncionVisitante visitar) {
  if (indiceActual >= max) return;
  
  aux_in(datos, hijoi(indiceActual), max, visitar);
  
  visitar(datos[indiceActual]);
  
  aux_in(datos, hijod(indiceActual), max, visitar);
}

static void aux_pre(int *datos, int indiceActual, size_t max, FuncionVisitante visitar) {
  if (indiceActual >= max) return;
  
  visitar(datos[indiceActual]);
  
  aux_in(datos, hijoi(indiceActual), max, visitar);
  
  aux_in(datos, hijod(indiceActual), max, visitar);
}

static void aux_post(int *datos, int indiceActual, size_t max, FuncionVisitante visitar) {
  if (indiceActual >= max) return;

  aux_in(datos, hijoi(indiceActual), max, visitar);
  
  aux_in(datos, hijod(indiceActual), max, visitar);
  
  visitar(datos[indiceActual]);
}

void cbtree_recorrer(CBTree arbol, BTreeOrdenDeRecorrido recorrido,
                     FuncionVisitante visitar) {
  if (!arbol) return;
  
  if (recorrido == BTREE_RECORRIDO_IN) {
    aux_in(arbol->datos, 0, arbol->nelems, visitar);
  } else if (recorrido == BTREE_RECORRIDO_POST) {
    aux_post(arbol->datos, 0, arbol->nelems, visitar);
  } else if (recorrido == BTREE_RECORRIDO_PRE) {
    aux_pre(arbol->datos, 0, arbol->nelems, visitar);
  }
}

void cbtree_recorrer_bfs(CBTree arbol, FuncionVisitante visitar) {
  for(int i = 0; i < arbol->nelems; i++) {
    visitar(arbol->datos[i]);
  }
}
