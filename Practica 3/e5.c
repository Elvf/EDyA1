#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_COLA 10

typedef struct _Cola {
  int datos[MAX_COLA];
  int primero, ultimo;
} *Cola;

Cola cola_inicializar() {
  Cola nuevaCola = malloc(sizeof(struct _Cola));
  nuevaCola->primero = -1;
  nuevaCola->ultimo = -1;
  
  return nuevaCola;
}

int cola_es_vacia(Cola c) {
  return (c->primero == -1);
}

int cola_primero(Cola c) {
  assert(c->primero == -1);
  return (c->datos[c->primero]);
}
