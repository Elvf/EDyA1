#ifndef __GLIST_H__
#define __GLIST_H__

#include <stddef.h>

/* Definimos tipos de punteros a funciones comparadora y visitante */
typedef void (*FuncionVisitante) (void *dato);
typedef int (*FuncionComparadora) (void *dato1, void *dato2);

typedef struct _GNodo {
	void *dato;
	struct _GNodo *sig;
} GNodo;

typedef GNodo *GList;

/* Crear una lista */
GList glist_crear(void);

/* Destruir una lista */
void glist_destruir(GList lista);

/* Obtener la longitud de una lista */
size_t glist_longitud(GList lista);

/* Agregar elementos */
GList glist_agregar_inicio(GList lista, void *dato);
GList glist_agregar_final(GList lista, void *dato);
GList glist_insertar(GList lista, void *dato, size_t pos);

/* Recorrer aplicando funcion a cada elemento */
void glist_recorrer(GList lista, FuncionVisitante visitar);

/* Concatenar dos listas */
GList glist_concat(GList lista1, GList lista2);

/* Eliminar en posicion arbitraria */
GList glist_eliminar(GList lista, size_t pos);

/* Verificar si hay al menos 1 elemento */
size_t glist_contiene(GList lista, void *dato);

/* Devuelve la posicion de la primera ocurrencia del dato */
size_t glist_indice(GList lista, void *dato);

/* Interseca dos listas */
GList glist_intersec(GList lista1, GList lista2);
GList glist_intersec_custom(GList lista1, GList lista2, FuncionComparadora comp);

/* Ordena una lista segun una funcion comparadora */
GList glist_ordenar(GList lista, FuncionComparadora comp);

/* Obtiene el reverso de la lista */
GList glist_reverso(GList lista);

/* Intercala dos listas */
GList glist_intercalar(GList lista1, GList lista2);

#endif /* __GLIST_H__ */
