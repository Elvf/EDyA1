#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();
  SList lista2 = slist_crear();
  unsigned int longitud;

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);
  
  lista2 = slist_agregar_inicio(lista2, 2);
  lista2 = slist_agregar_inicio(lista2, 1);
  lista2 = slist_agregar_inicio(lista2, 6);
  lista2 = slist_agregar_final(lista2, 7);

  slist_recorrer(lista, imprimir_entero);
  puts("");
  
  longitud = slist_longitud(lista);
  printf("Long: %d\n", longitud);

  slist_concatenar(lista, lista2);
  
  slist_recorrer(lista, imprimir_entero);
  puts("");

  lista2 = slist_insertar(lista2, 4, -1);

  slist_recorrer(lista2, imprimir_entero);
  puts("");
  
  lista2 = slist_eliminar(lista2, 4);
  
  slist_recorrer(lista2, imprimir_entero);
  puts("");

  slist_destruir(lista);

  return 0;
}
