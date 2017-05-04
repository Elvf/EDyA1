#include <stdio.h>
#include <stdlib.h>

#define MAX_PILA 10

typedef struct _Pila {
  int datos[MAX_PILA];
  int ultimo;
} *Pila;

Pila pilaCrear() {
  Pila nuevaPila = malloc(sizeof(struct _Pila));
  nuevaPila->ultimo = -1;
  
  return nuevaPila;
}

int pilaEsVacia(Pila p) {
  return (p->ultimo == -1);
}

int *pilaTop(Pila p) {
  return ((pilaEsVacia(p)) ? NULL : &(p->datos[p->ultimo]));
}

int pilaPush(Pila p, int d) {
  if (p->ultimo + 1 == MAX_PILA) return 1;
  
  p->datos[++(p->ultimo)] = d;
  return 0;
}

int *pilaPop(Pila p) {
  int *a = pilaTop(p);
  
  if (a) (p->ultimo)--;
  return a;
}

void imprimirPila(Pila p) {
  for (int i = 0; i <= p->ultimo; i++) {
    printf("[%4d] ", p->datos[i]);
  }
  puts(" ");
}

int main (int argc, char *argv[]) {
  Pila test = pilaCrear();
  int result, *a;
  
  result = pilaPush(test, 4);
  result = pilaPush(test, 7);
  result = pilaPush(test, 3);
  result = pilaPush(test, 4);
  result = pilaPush(test, 1);
  result = pilaPush(test, 0);
  result = pilaPush(test, 22);
  result = pilaPush(test, 173);
  
  imprimirPila(test);
  
  a = pilaPop(test);
  a = pilaPop(test);
  
  result = pilaPush(test, 1969);
  result = pilaPush(test, 42);
  
  a = pilaTop(test);
  
  imprimirPila(test);
  
  printf("El tope es: %d", *a);
  
  return 0;
}
