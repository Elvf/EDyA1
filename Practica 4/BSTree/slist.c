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

size_t slist_longitud (SList lista) {
  unsigned int counter = 0;
  
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    counter++;
    
  return counter;
}

SList slist_concatenar(SList lista1, SList lista2) {
  if (lista1 == NULL) {
    return lista2;
  }
  
  SNodo *nodo = lista1;
  
  for (; nodo->sig != NULL; nodo = nodo->sig);
  
  nodo->sig = lista2;
  
  return lista1;
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
    if (nodo->dato == elemento)
      return 1; /*Asumiendo que 1 es TRUE */
  }
  
  return 0; /* Asumiendo que 0 es FALSE */
}

unsigned int slist_indice(SList lista, int dato){
  int i = 0;
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig) {
    if (nodo->dato == dato)
      return i;
    
    i++;
  }
  
  return -1;
}

SList slist_intersecar(SList lista1, SList lista2) {
  SList interseccion = NULL;
  
  for (SNodo *nodo = lista1; nodo != NULL; nodo = nodo->sig) {
    if (slist_contiene(lista2, nodo->dato))
      interseccion = slist_agregar_inicio(interseccion, nodo->dato);
  }
  
  return interseccion;
}

SList slist_intersecar_custom(SList lista1, SList lista2, FuncionComparadora comp) {
  SList customInterseccion = NULL;
  
  for (SNodo *nodo = lista1; nodo != NULL; nodo = nodo->sig) {
    for (SNodo *nodo2 = lista2; nodo2 != NULL; nodo2 = nodo2->sig) {
      if (comp(nodo->dato, nodo2->dato)) {
        customInterseccion = slist_agregar_inicio(customInterseccion, nodo->dato);
      }
    }
  }
  
  return customInterseccion;
}

SList slist_ordenar(SList lista, FuncionComparadora comp) {
  /* La lista ya esta ordenada si solo tiene un elemento o es vacia */
  if (lista == NULL || lista->sig == NULL) return lista;
  
  int comparaciones;
  
  for (comparaciones = 0; comparaciones < slist_longitud(lista); comparaciones++) {
    SList actual = lista;
    SList siguiente = lista->sig;
    SList previo = NULL;
    
    while (siguiente != NULL) {
      if (comp(actual->dato, siguiente->dato)) {
        if (actual == lista)
          lista = siguiente;
        else
          previo->sig = siguiente;
        
        actual->sig = siguiente->sig;
        siguiente->sig = actual;
        
        previo = siguiente;
        siguiente = actual->sig;
      } else {
        previo = actual;
        actual = actual->sig;
        siguiente = siguiente->sig;
      }
    }
  }
  
  return lista;
}

SList slist_reverso(SList lista) {
  SList ultimo = NULL;
  SList siguiente = NULL;
  SList resultado = NULL;
  
  while (lista) {
    siguiente = lista->sig;
    lista->sig = ultimo;
    ultimo = lista;
    resultado = lista;
    lista = siguiente;
  }
  
  return resultado;
}

SList slist_reverso_v2 (SList lista) {
  SList nuevaLista = NULL;
  
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    nuevaLista = slist_agregar_inicio(nuevaLista, nodo->dato);
    
  return nuevaLista;
}

SList slist_intercalar(SList lista1, SList lista2) {
  if (lista1 == NULL && lista2 == NULL)
    return lista1;
  else if (lista1 == NULL)
    return lista2;
  else if (lista2 == NULL)
    return lista1;
  
  SList listaIntercalada = NULL;
  
  if (slist_longitud(lista1) >= slist_longitud(lista2)) {
    SList nodo2 = lista2;
    
    for (SNodo *nodo = lista1; nodo != NULL; nodo = nodo->sig) {
      listaIntercalada = slist_agregar_final(listaIntercalada, nodo->dato);
      
      if (nodo2) {
        listaIntercalada = slist_agregar_final(listaIntercalada, nodo2->dato);
        nodo2 = nodo2->sig;
      }
    }
  } else {
    SList nodo1 = lista1;
    
    for (SNodo *nodo = lista2; nodo != NULL; nodo = nodo->sig) {
      if (nodo1) {
        listaIntercalada = slist_agregar_final(listaIntercalada, nodo1->dato);
        nodo1 = nodo1->sig;
      }
      
      listaIntercalada = slist_agregar_final(listaIntercalada, nodo->dato);
    }
  }
  
  return listaIntercalada;
}
