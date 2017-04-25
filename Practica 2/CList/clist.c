#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

CList clist_crear(void) {
  return NULL;
}

void clist_destruir(CList lista) {
  CNodo *nodoAEliminar;
  CNodo *primero = lista;
  lista = lista->sig;
  
  while (lista->sig != primero) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
  
  free(primero);
}

CList clist_agregar_inicio(CList lista, int dato) {
  CNodo *nuevoNodo = malloc(sizeof(CNodo));
  nuevoNodo->dato = dato;
  
  if (lista) {
    nuevoNodo->sig = lista;
    
    CNodo *nodo;
    for (nodo = lista; nodo->sig != lista; nodo = nodo->sig);
    
    nodo->sig = nuevoNodo;
  } else {
    nuevoNodo->sig = nuevoNodo;
  }
  
  return nuevoNodo;
}

void clist_recorrer(CList lista, FuncionVisitante f) {
  f(lista->dato);
  
  for (CNodo *nodo = lista->sig; nodo != lista; nodo = nodo->sig)
    f(nodo->dato);
}
