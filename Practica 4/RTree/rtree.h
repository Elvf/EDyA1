#ifndef __RTREE_H__
#define __RTREE_H__

#include <stddef.h>
#include "glist.h"

typedef struct _RTNode {
	void *dato;
	GList hijos;
} RTNode;

typedef RTNode *RTree;

RTree rtree_crear(void);

void rtree_destruir(RTree arbol);

RTree rtree_agregar(RTree padre, void *dato);

void rtree_recorrer(RTree arbol, FuncionVisitante visit);

#endif /* __RTREE_H__ */
