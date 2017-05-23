#include <stdlib.h>
#include "tqueue.h"

TQueue tqueue_crear(void) {
  return NULL;
}

TQueue tqueue_encolar(TQueue c, BTree nodo) {
  TQueueNode *newNode = malloc(sizeof(TQueueNode));
  newNode->currentNode = nodo;
  
  if (!c) {
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
  } else {
    newNode->next = c;
    newNode->prev = c->prev;
    c->prev->next = newNode;
    c->prev = newNode;
    return c;
  }
}

void tqueue_desencolar(TQueue c) {
  if (c) {
    TQueueNode *temp = c;
    c->prev->next = c->next;
    c->next->prev = c->prev;
    c = c->next;
    
    free(temp);
  } else return;
}

void tqueue_destruir(TQueue c) {
  TQueueNode *nodo = c->next;
  TQueueNode *temp;
  
  while(nodo != c) {
    temp = nodo;
    nodo = nodo->next;
    free(temp);
  }
}
