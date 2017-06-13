#include <stdio.h>
#include "glist.h"

static void imprimir_entero(void *dato) {
  printf("%d ", *((int *)dato));
}

static void mult_2(void *dato) {
  *((int *)dato) = *((int *)dato) * 2;
}

int main(int argc, char *argv) {
  GList lista = glist_crear();
  
  lista = glist_agregar_final(lista, (void *) 5);
  lista = glist_agregar_final(lista, (void *) 4);
  lista = glist_agregar_final(lista, (void *) 3);
  lista = glist_agregar_final(lista, (void *) 2);
  
  glist_recorrer(lista, imprimir_entero);
  puts("");
  
  glist_recorrer(lista, mult_2);
  
  glist_recorrer(lista, imprimir_entero);
  puts("");
  
  lista = glist_eliminar(lista, 0);
  
  glist_recorrer(lista, imprimir_entero);
  puts("");
  
  return 0;
}
