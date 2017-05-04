#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int dato;
  struct _Node *next;
} Node;

typedef Node *Pila; /* puto */

Pila pilaCrear(void) {
  return NULL;
}

int pilaEsVacia(Pila p) {
  return (p == NULL);
}

int *pilaTop(Pila p) {
  return ((pilaEsVacia(p)) ? NULL : &(p->dato));
}

Pila pilaPush(Pila p, int d) {
  Node *nuevoNodo = malloc(sizeof(Node));
  nuevoNodo->dato = d;
  nuevoNodo->next = p;
  
  return nuevoNodo;
}

Pila pilaPop(Pila p) {
  if (pilaEsVacia(p)) return p;
  
  Node *lib = p;
  p = p->next;
  free(lib);
  
  return p;
}

void imprimirPila(Pila p) {
  for (Node *nodo = p; nodo != NULL; nodo = nodo->next)
    printf("[%4d] ", nodo->dato);
    
  puts(" ");
}

void destruirPila(Pila p) {
  Node *lib;
  
  if (!pilaEsVacia(p)) {
    while(p) {
      lib = p;
      p = p->next;
      free(lib);
    }
  }
}

int main (int argc, char *argv[]) {
  Pila test = pilaCrear();
  
  test = pilaPush(test, 42);
  test = pilaPush(test, 121);
  test = pilaPush(test, 3);
  
  imprimirPila(test);
  
  test = pilaPop(test);
  
  imprimirPila(test);
  
  destruirPila(test);
  
  return 0;
}
