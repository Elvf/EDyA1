#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#include "pila.h"

Pila pilaCrear(void) {
  return NULL;
}

int pilaEsVacia(Pila p) {
  return (p == NULL);
}

int *pilaTop(Pila p) {
  return ((pilaEsVacia(p)) ? NULL : &(p->dato));
}

Pila pilaPush(Pila p, int d) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = d;
  nuevoNodo->sig = p;
  
  return nuevoNodo;
}

Pila pilaPop(Pila p) {
  if (pilaEsVacia(p)) return p;
  
  SNodo *lib = p;
  p = p->sig;
  free(lib);
  
  return p;
}

void imprimirPila(Pila p) {
  for (SNodo *nodo = p; nodo != NULL; nodo = nodo->sig)
    printf("[%4d] ", nodo->dato);
    
  puts(" ");
}

void destruirPila(Pila p) {
  SNodo *lib;
  
  if (!pilaEsVacia(p)) {
    while(p) {
      lib = p;
      p = p->sig;
      free(lib);
    }
  }
}

SList slistReversoPila(SList lista) {
  Pila reverso = pilaCrear();
  
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    reverso = pilaPush(reverso, nodo->dato);
    
  slist_destruir(lista);
  
  return reverso;
}
