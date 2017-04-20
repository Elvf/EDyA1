#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int dosEquis (int a, int b) {
  return (a == 2 * b);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();
  SList lista2 = slist_crear();
  SList interseccion, interseccion2, intercalada;
  unsigned int longitud;
  int index, index2;

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
  
  /**
   * Funcion Longitud
   */
  longitud = slist_longitud(lista);
  printf("Longitud lista 1: %d\n", longitud);
  puts("");

  /**
   * Funcion Concatenar
   */
  slist_concatenar(lista, lista2);
  
  puts("Listas concatenadas en Lista 1:");
  slist_recorrer(lista, imprimir_entero);
  puts("\n");
  
  /**
   * Funciones Insertar y Eliminar
   */
  lista2 = slist_insertar(lista2, 3, -1);

  puts("Insertado elemento -1 en posicion 3 en Lista 2");
  slist_recorrer(lista2, imprimir_entero);
  puts("\n");
  
  lista2 = slist_eliminar(lista2, 4);
  
  puts("Eliminado item en el indice 4 de lista 2");
  slist_recorrer(lista2, imprimir_entero);
  puts("\n");

  /**
   * Funcion Contiene
   */
  if (slist_contiene(lista, 3))
    printf("La lista 1 contiene el elemento 3\n");

  /**
   * Funcion Indice
   */
  index = slist_indice(lista, 9);
  index2 = slist_indice(lista2, 2);

  printf("\n[Index]: %d\n[Index2]: %d\n", index, index2);

  /**
   * Funcion Intersecar
   */
  interseccion = slist_intersecar(lista, lista2);
  
  puts("Lista interseccion entre lista1 y lista2");
  slist_recorrer(interseccion, imprimir_entero);
  puts("\n");
  
  /**
   * Funcion Intersecar Custom
   */
  interseccion2 = slist_intersecar_custom(lista, lista2, dosEquis);
  puts("Lista interseccion custom entre lista1 y lista2");
  slist_recorrer(interseccion2, imprimir_entero);
  puts("\n");
  
  /**
   * Funcion Ordenar
   */
  
  /* DEBUG */
  slist_recorrer(lista2, imprimir_entero); // Aca lista2 sigue igual
  puts("\n");
  
  /**
   * Funcion Reverso
   */
  lista = slist_reverso(lista);

  puts("Lista 1 invertida");
  slist_recorrer(lista, imprimir_entero);
  puts("\n");
  
  /**
   * ERROR
   * Por algun motivo, aca es donde cambia lista2
   * PREGUNTAR !!
   */
  slist_recorrer(lista2, imprimir_entero);
  puts("\n");
  
  /**
   * Funcion Intercalar
   */
  printf("Listas a intercalar:\n[Lista 1]: ");
  slist_recorrer(lista, imprimir_entero);
  puts("");
  printf("[Lista 2]: ");
  slist_recorrer(lista2, imprimir_entero);
  puts("");
  
  intercalada = slist_intercalar(lista, lista2);

  slist_recorrer(intercalada, imprimir_entero);
  puts("");

  /**
   * Funcion Destruir
   */
  slist_destruir(lista);
  slist_destruir(lista2);
  slist_destruir(interseccion);
  slist_destruir(intercalada);

  return 0;
}
