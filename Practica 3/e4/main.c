#include <stdio.h>
#include "slist.h"
#include "pila.h"

int main(int argc, char *argv[]) {
  SList lista = slist_crear();
  
  lista = slist_agregar_final(lista, 42);
  lista = slist_agregar_final(lista, 20);
  lista = slist_agregar_final(lista, 14);
  lista = slist_agregar_final(lista, 39);
  lista = slist_agregar_final(lista, 1);
  lista = slist_agregar_final(lista, 182);
  
  imprimirPila(lista);
  
  lista = slistReversoPila(lista);
  
  imprimirPila(lista);
  
  return 0;
}
