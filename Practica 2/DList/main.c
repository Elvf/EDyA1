#include <stdio.h>
#include "dlist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {
  DList lista = dlist_crear();
  
  lista = dlist_agregar_final(lista, 4);
  lista = dlist_agregar_final(lista, 2);
  lista = dlist_agregar_inicio(lista, 3);
  lista = dlist_agregar_inicio(lista, 5);
  lista = dlist_agregar_inicio(lista, 6);
  
  dlist_recorrer(lista, imprimir_entero, DLIST_RECORRIDO_HACIA_ADELANTE);
  puts("");
  
  dlist_recorrer(lista, imprimir_entero, DLIST_RECORRIDO_HACIA_ATRAS);
  puts("");
  
  dlist_destruir(lista);
  
  return 0;
}
