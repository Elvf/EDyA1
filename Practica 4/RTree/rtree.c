#include <stdlib.h>
#include "rtree.h"

RTree rtree_crear(void) {
  return NULL;
}

RTree rtree_agregar(RTree padre, void *dato) {
  RTree newTree = malloc(sizeof(RTNode));
  newTree->dato = malloc(sizeof(dato));
  newTree->dato = dato;
  newTree->hijos = glist_crear();
  
  if (!padre)
    return newTree;
  
  padre->hijos = glist_agregar_final(padre->hijos, (void *)newTree);
  return padre;
}

void rtree_destruir(RTree arbol) {
  if (!arbol) return;
  
  GList aux = arbol->hijos;
  
  for(; aux != NULL; aux = aux->sig)
    rtree_destruir((RTree)aux);
    
  free(arbol);
}

void rtree_recorrer(RTree arbol, FuncionVisitante visitar) {
  if (!arbol) return;
  
  visitar(arbol);
  
  GList aux = arbol->hijos;
  
  for(; aux != NULL; aux = aux->sig)
    rtree_recorrer((RTree)(aux->dato), visitar);
}
