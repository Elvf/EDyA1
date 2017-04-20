#include <stdio.h>
#include <stdlib.h>
/**
 * Guardamos los datos en 1 arreglo, y los indices de los siguientes en
 * otro, y el indice del primer elemento en una variable extra.
 * 
 *      Datos: [ 1 |  2 |  3 |       garbage       |]
 * Siguientes: [ 1 |  2 | -1 |       garbage       |]
 *     Usados: [ 1 |  1 |  1 |  0 |  0 | ...       |]
 *    Primero: 0
 *     Ultimo: 2
 *   Longitud: 10
 * 
 * Supongamos que queremos agregar el elemento 15 al final de la lista.
 * Entonces nos queda:
 * 
 *      Datos: [ 1 |  2 |  3 | 15 |      garbage       |]
 * Siguientes: [ 1 |  2 |  3 | -1 |      garbage       |]
 *     Usados: [ 1 |  1 |  1 |  1 |  0 | ...           |]
 *    Primero: 0
 *     Ultimo: 3
 *   Longitud: 10
 */

typedef struct {
  size_t tamanio;
  int *datos;
  int *siguientes;
  char *usados;
  int primero;
  int ultimo;
} lista;

lista *lista_crear (size_t tamanio) {
  lista *nuevaLista = (lista *)malloc(sizeof(lista));
  
  nuevaLista->tamanio = tamanio;
  nuevaLista->datos = (int *)malloc(sizeof(int) * tamanio);
  nuevaLista->siguientes = (int *)malloc(sizeof(int) * tamanio);
  nuevaLista->usados  = (char *)malloc(sizeof(char) * tamanio);
  
  nuevaLista->primero = -1;
  nuevaLista->ultimo = -1;
  
  return nuevaLista;
}

int lista_agregar_principio (lista *list, int dato) {
  if (list->primero == -1) {
    list->primero = 0;
    list->ultimo = 0;
    list->datos[0] = dato;
    list->usados[0] = 1;
    list->siguientes[0] = -1;
    
    return 0;
  }
  
  int posicion = 0;
  
  while (posicion < list->tamanio && list->usados[posicion])
    posicion++;
    
  if (posicion == list->tamanio)
    return 1; /* ERROR - No hay mas espacio en la lista */
  
  list->datos[posicion] = dato;  
  list->usados[posicion] = 1;
  list->siguientes[posicion] = list->primero;
  list->primero = posicion;
  
  return 0;
}

int main(int argc, char *argv[]) {
  return 0;
}
