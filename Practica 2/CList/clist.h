#ifndef __CLIST_H__
#define __CLIST_H__

#include <stddef.h>

typedef struct _CNodo {
  int dato;
  struct _CNodo *sig;
} CNodo;

typedef CNodo *CList;
typedef void (*FuncionVisitante) (int dato);

CList clist_crear(void);

void clist_destruir(CList lista);

CList clist_agregar_inicio(CList lista, int dato);

void clist_recorrer(CList lista, FuncionVisitante f);

#endif /* __CLIST_H__ */
