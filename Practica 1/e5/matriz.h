#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <stdlib.h>

typedef struct Matriz_ Matriz;

/*
** Crea una nueva matriz
*/
Matriz* matriz_crear(size_t wantRow, size_t wantCol); // We're gonna put some mallocs here lol

/*
** Destruye una matriz
*/
void matriz_destruir(Matriz* mat); // FREE THE MATRIXES!!!!!

/*
** Obtiene el dato guardado en la posición dada de la matriz
*/
double matriz_leer(Matriz* mat, size_t row, size_t col);

/*
** Modifica el dato guardado en la posición dada de la matriz
*/
void matriz_escribir(Matriz* mat, size_t row, size_t col, double val);

/*
** Obtiene número de filas de la matriz
*/
size_t matriz_num_filas(Matriz* matriz);

/*
** Obtiene número de columnas de la matriz
*/
size_t matriz_num_columnas(Matriz* matriz);

/**
 * Intercambia la fila I con la fila J de la matriz
 */
void matriz_intercambiar_filas(Matriz* mat, size_t rowI, size_t rowJ);

/**
 * Agrega una fila a la matriz en la posicion i
 */
Matriz* matriz_insertar_fila(Matriz* mat, float arr[], size_t arraySize, size_t insertAfter);

/**
 * Imprime una matriz
 */
void matriz_imprimir(Matriz* mat);

#endif /* __MATRIZ_H__ */
