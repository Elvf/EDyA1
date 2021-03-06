#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef enum {
  DLIST_RECORRIDO_HACIA_ADELANTE,
  DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;

typedef struct _DNodo {
  int dato;
  struct _DNodo *sig;
  struct _DNodo *prev;
} DNodo;

typedef DNodo *DList;

/**
 * Devuelve una lista vacía.
 */
DList dlist_crear();

/**
 * Destruccion de la lista.
 */
void dlist_destruir(DList lista);

/**
 * Determina si la lista es vacía.
 */
int dlist_vacia(DList lista);

/**
 * Agrega un elemento al final de la lista.
 */
DList dlist_agregar_final(DList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
DList dlist_agregar_inicio(DList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void dlist_recorrer(DList lista, FuncionVisitante visit, DListOrdenDeRecorrido recorrido);

#endif /* __DLIST_H__ */
