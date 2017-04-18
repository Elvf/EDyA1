#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

unsigned int slist_longitud (SList lista) {
  unsigned int counter = 0;
  
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    counter++;
    
  return counter;
}

void slist_concatenar(SList lista1, SList lista2) {
  if (lista1 == NULL) {
    printf("NO ME PASES UNA LISTA NULA, FORRO!\n");
    return;
  }
  
  SNodo *nodo = lista1;
  
  for (; nodo->sig != NULL; nodo = nodo->sig);
  
  nodo->sig = lista2;
}

SList slist_insertar(SList lista, unsigned int posicion, int dato) {  
  if (posicion == 0) {
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = lista;
    
    return nuevoNodo;
  }
  
  if (posicion > slist_longitud(lista))
    return lista;
    
  SNodo *copia = lista;
  
  for (int i = 0; i < posicion - 1; i++)
    copia = copia->sig;
    
  SNodo *sigViejo = copia->sig;
  
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = sigViejo;
  
  copia->sig = nuevoNodo;
  
  return lista;
}

SList slist_eliminar(SList lista, unsigned int posicion) {
  if (posicion > slist_longitud(lista) || lista == NULL) {
    return lista;
  }
  
  if (posicion == 0) {
    SNodo *siguiente = lista->sig;
    free(lista);
    
    return siguiente;
  }
  
  SList copia = lista;
  
  for (int i = 0; i < posicion - 1; i++)
    copia = copia->sig;
  
  if (copia->sig->sig == NULL) {
    SNodo *lib = copia->sig;
    copia->sig = NULL;
    
    free(lib);
  } else {
    SNodo *lib = copia->sig;
    SNodo *aux = copia->sig->sig;
    copia->sig = aux;
    
    free(lib);
  }
  
  return lista;
}

unsigned int slist_contiene(SList lista, int elemento) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig) {
    if (nodo->dato == elemento) {
      return 1; /*Asumiendo que 1 es TRUE */
    }
  }
  
  return 0; /* Asumiendo que 0 es FALSE */
}

/*
unsigned int slist_indice(SList lista, int dato);

SList slist_intersecar(SList lista1, SList lista2);

SList slist_intersecar_custom(SList lista1, SList lista2, FuncionVisitante comp);

void slist_ordenar(SList lista, FuncionVisitante comp);

SList slist_reverso(SList lista);

SList slist_intercalar(SList lista1, SList lista2);
*/
