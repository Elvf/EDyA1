#ifndef __PILA_H__
#define __PILA_H__

#include <stddef.h>
#include "slist.h"

typedef SList Pila;

Pila pilaCrear(void);
int pilaEsVacia(Pila p);
int *pilaTop(Pila p);
Pila pilaPush(Pila p, int d);
Pila pilaPop(Pila p);
void imprimirPila(Pila p);
void destruirPila(Pila p);
SList slistReversoPila(SList lista);

#endif /* __PILA_H__ */
