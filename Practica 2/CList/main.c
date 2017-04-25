#include <stdio.h>
#include "clist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {
  CList lista = clist_crear();
  
  lista = clist_agregar_inicio(lista, 4);
  lista = clist_agregar_inicio(lista, 2);
  lista = clist_agregar_inicio(lista, 3);
  lista = clist_agregar_inicio(lista, 6);
  
  clist_recorrer(lista, imprimir_entero);
  puts("");
  
  clist_destruir(lista);
  
  return 0;
}
