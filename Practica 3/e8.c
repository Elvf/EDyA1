#include <stdlib.h>

#define MAX_PCOLA 6

typedef struct {
  int dato;
  int prioridad;
} Item;

typedef struct {
  Item datos[MAX_PCOLA];
  int primero, ultimo;
} *PCola;

PCola cola_prioridad_crear(void) {
  PCola newPQ = malloc(sizeof(PCola));
  newPQ->primero = -1;
  newPQ->ultimo = -1;
  
  return newPQ;
}

int cola_prioridad_es_vacia(PCola p) {
  return (p->primero == -1);
}

int cola_prioridad_obtener_minimo(PCola p) {
  
}
