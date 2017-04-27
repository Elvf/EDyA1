#ifndef __XLIST_H__
#define __XLIST_H__

#include <stddef.h>
#include <stdint.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _XNodo {
  int dato;
  struct _XNodo *npx;
} XNodo;

typedef XNodo *XList;

XList xlist_crear();

XList xlist_xor(XNodo *nodo1, XNodo *nodo2);

void xlist_destruir(XList lista);

int xlist_vacia(XList lista);

XList xlist_agregar_final(XList lista, int dato);

XList xlist_agregar_inicio(XList lista, int dato);

void xlist_recorrer(XList lista, FuncionVisitante visitar);

#endif /* __XLIST_H__ */
