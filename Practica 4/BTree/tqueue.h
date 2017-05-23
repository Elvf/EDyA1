#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <stddef.h>
#include "btree.h"

typedef struct _TQueueNode {
  BTree currentNode;
  struct _TQueueNode *next;
  struct _TQueueNode *prev;
} TQueueNode;

typedef TQueueNode *TQueue;

TQueue tqueue_crear(void);
TQueue tqueue_encolar(TQueue c, BTree nodo);
TQueue tqueue_desencolar(TQueue c);
void tqueue_destruir(TQueue c);

#endif /* __TQUEUE_H__ */
