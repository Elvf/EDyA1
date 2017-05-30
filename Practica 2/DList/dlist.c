#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

DList dlist_crear() {
  return NULL;
}

void dlist_destruir(DList lista) {
  if (lista) {
    if (lista->sig != lista) {
      DNodo *tmp = lista;
      lista = lista->sig;
      
      for (; lista != tmp; lista = lista->sig)
        free(lista);
      
      free(tmp);
    } else free(lista);
  }
}

int dlist_vacia(DList lista) {
  return lista == NULL;
}

DList dlist_agregar_final(DList lista, int dato) {
  if (!lista) {
    lista = malloc(sizeof(DNodo));
    
    lista->dato = dato;
    lista->sig = lista;
    lista->prev = lista;
    
    return lista;
  }
  
  DNodo *nuevoNodo = malloc(sizeof(DNodo));
  
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  nuevoNodo->prev = lista->prev;
  lista->prev->sig = nuevoNodo;
  lista->prev = nuevoNodo;
  
  return lista;
}

DList dlist_agregar_inicio(DList lista, int dato) {
  if (!lista) {
    lista = malloc(sizeof(DNodo));
    
    lista->dato = dato;
    lista->sig = lista;
    lista->prev = lista;
    
    return lista;
  }
  
  DNodo *nuevoNodo = malloc(sizeof(DNodo));
  
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  nuevoNodo->prev = lista->prev;
  lista->prev->sig = nuevoNodo;
  lista->prev = nuevoNodo;
  
  return nuevoNodo;
}

void dlist_recorrer(DList lista, FuncionVisitante visit, DListOrdenDeRecorrido recorrido) {
  if (!lista) return;
  
  if (recorrido == DLIST_RECORRIDO_HACIA_ADELANTE) {
    
    visit(lista->dato);
    
    for (DNodo *nodo = lista->sig; nodo != lista; nodo = nodo->sig)
      visit(nodo->dato);
      
  } else if (recorrido == DLIST_RECORRIDO_HACIA_ATRAS) {
    
    visit(lista->prev->dato);
    
    for (DNodo *nodo = lista->prev->prev; nodo != lista->prev; nodo = nodo->prev)
      visit(nodo->dato);
      
  } else {
    puts("Pero vos sos bobo o te haces?!");
    return;
  }
}
