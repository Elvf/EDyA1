#ifndef __ALIST_H__
#define __ALIST_H__

#include <stddef.h>

typedef struct {
  int *datos;
  size_t ultimo;
  size_t capacidad;
} _AList;

typedef _AList *AList;

/* Crear lista */
AList alist_crear(void);

void alist_destruir(AList lista);

int alist_vacia(AList lista);

void alist_agregar(AList lista, int dato);

#endif /* __ALIST_H__ */
