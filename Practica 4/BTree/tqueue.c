#include <stdio.h>
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

TQueue tqueue_desencolar(TQueue c) {
  if (!c) return NULL;
  
  if (c->next == c) {
    free(c);
    return NULL;
  } else {
    TQueueNode *tmp = c->next;
    c->prev->next = c->next;
    c->next->prev = c->prev;
    
    free(c);
    return tmp;
  }
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
