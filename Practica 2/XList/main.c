#include <stdio.h>
#include "xlist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {
  XList test = xlist_crear();
  
  test = xlist_agregar_inicio(test, 4);
  test = xlist_agregar_inicio(test, 2);
  test = xlist_agregar_inicio(test, 6);
  test = xlist_agregar_inicio(test, 3);
  test = xlist_agregar_final(test, 7);
  test = xlist_agregar_final(test, 42);
  
  xlist_recorrer(test, imprimir_entero);
  puts("");
  
  return 0;
}
