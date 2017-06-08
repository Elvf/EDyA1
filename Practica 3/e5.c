#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_COLA 6

typedef struct _Cola {
  int datos[MAX_COLA];
  int primero, ultimo;
} *Cola;

Cola cola_inicializar(void) {
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

void cola_encolar(Cola c, int d) {
  if (cola_es_vacia(c)) {
    c->primero = 0;
    c->ultimo = 0;
    c->datos[0] = d;
    return;
  }

  if (((c->ultimo + 1) % MAX_COLA) == c->primero)
    return;
    
  c->ultimo = (c->ultimo + 1) % MAX_COLA;
  c->datos[c->ultimo] = d;
}

void cola_desencolar(Cola c) {
  if (c->ultimo == c->primero)
    return;
    
  c->primero = (c->primero + 1) % MAX_COLA;
}

void cola_imprimir(Cola c) {
  int i;
  
  for(i = c->primero; i != c->ultimo; i = ((i + 1) % MAX_COLA))
    printf("%4d ", c->datos[i]);
    
  printf("%4d ", c->datos[c->ultimo]);
  puts("");
}

int main(int argc, char *argv[]) {
  Cola c = cola_inicializar();
  
  cola_encolar(c, 4);
  cola_encolar(c, 5);
  cola_encolar(c, 3);
  cola_encolar(c, 0);
  cola_encolar(c, 2);
  cola_encolar(c, 9);
  
  cola_imprimir(c);
  
  cola_desencolar(c);
  
  cola_imprimir(c);
  
  cola_encolar(c, 15);
  
  cola_imprimir(c);
  
  cola_desencolar(c);
  cola_desencolar(c);
  
  cola_imprimir(c);
  
  return 0;
}
