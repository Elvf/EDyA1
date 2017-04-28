#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "xlist.h"

XList xlist_crear() {
  return NULL;
}

XList xlist_xor(XNodo *nodo1, XNodo *nodo2) {
  return (XNodo *) ((uintptr_t) nodo1 ^ (uintptr_t) nodo2);
}

void xlist_destruir(XList lista) {
  if (lista) {
    if (xlist_xor(NULL, lista->npx) != NULL) {
      XNodo *actual = xlist_xor(NULL, lista->npx);
      XNodo *prev = lista;
      XNodo *next;

      while (actual) {
          next = xlist_xor(prev, actual->npx);
          free(prev);
          prev = actual;
          actual = next;
      }

      free(lista);
    } else free(lista);
  }
}

int xlist_vacia(XList lista) {
  return (lista == NULL);
}

XList xlist_agregar_final(XList lista, int dato) {
  XNodo *nuevoNodo = malloc(sizeof(XNodo));
  nuevoNodo->dato = dato;

  if (lista) {
    XNodo *actual = lista;
    XNodo *prev = NULL;
    XNodo *next, *ant;

    while (actual) {
      next = xlist_xor(prev, actual->npx);
      prev = actual;
      actual = next;
    }

    nuevoNodo->npx = xlist_xor(prev, NULL);
    ant = xlist_xor(prev->npx, NULL);
    prev->npx = xlist_xor(ant, nuevoNodo);

    return lista;
  } else {
    nuevoNodo->npx = xlist_xor(NULL, NULL);

    return nuevoNodo;
  }
}

XList xlist_agregar_inicio(XList lista, int dato) {
  XNodo *nuevoNodo = malloc(sizeof(XNodo));
  nuevoNodo->dato = dato;

  nuevoNodo->npx = xlist_xor(lista, NULL);

  if (lista) {
    XNodo *siguiente = xlist_xor(lista->npx, NULL);
    lista->npx = xlist_xor(nuevoNodo, siguiente);
  }

  return nuevoNodo;
}

void xlist_recorrer(XList lista, FuncionVisitante visitar) {
  XNodo *actual = lista;
  XNodo *prev = NULL;
  XNodo *next;

  while (actual) {
    visitar(actual->dato);

    next = xlist_xor(prev, actual->npx);
    prev = actual;
    actual = next;
  }
}
