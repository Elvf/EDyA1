#include <stdlib.h>
#include "glist.h"

/* Crear una lista */
GList glist_crear(void) {
	return NULL;
}

/* Destruir una lista */
void glist_destruir(GList lista) {
	GNodo *nodoAEliminar;
	
	while (lista) {
		nodoAEliminar = lista;
		lista = lista->sig;
		free(nodoAEliminar);
	}
}

/* Obtener la longitud de una lista */
size_t glist_longitud(GList lista) {
	size_t contadorNodos;
	
	if (lista) {
		for (GNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
			contadorNodos++;
		
		return contadorNodos;
	} else return 0;
}

/* Agregar elementos */
GList glist_agregar_inicio(GList lista, void *dato) {
	GNodo *nuevoNodo = malloc(sizeof(GNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = lista; /* Agregamos al inicio */
	
	return nuevoNodo;
}

GList glist_agregar_final(GList lista, void *dato) {
	GNodo *nuevoNodo = malloc(sizeof(GNodo));
	GNodo *nodo;
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;
	
	if (!lista) return nuevoNodo;
	
	for (nodo = lista; nodo->sig != NULL; nodo = nodo->sig);
	
	nodo->sig = nuevoNodo;
	
	return lista;
}

GList glist_insertar(GList lista, void *dato, size_t pos) {
	GNodo *nodo, *nuevoNodo;
	
	if (pos == 0) {
		GNodo *nuevoNodo = malloc(sizeof(GNodo));
		nuevoNodo->dato = dato;
		nuevoNodo->sig = lista; /* Agregamos al inicio */
		
		return nuevoNodo;
	}
	
	if (pos > glist_longitud(lista)) return lista;
	
	nodo = lista;
	for (int i = 0; i < pos - 1; i++)
		nodo = nodo->sig;

	nuevoNodo = malloc(sizeof(GNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = nodo->sig;
	nodo->sig = nuevoNodo;
	
	return lista;
}

/* Recorrer aplicando funcion a cada elemento */
void glist_recorrer(GList lista, FuncionVisitante visitar) {
	for (GNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
		visitar(nodo->dato);
}

/* Concatenar dos listas */
GList glist_concat(GList lista1, GList lista2) {
	GNodo *nodo = lista1;
	
	if (!lista1) return lista2;
	if (!lista2) return lista1;
	
	for (; nodo->sig != NULL; nodo = nodo->sig);
	
	nodo->sig = lista2;
	
	return lista1;
}

/* Eliminar en posicion arbitraria */
GList glist_eliminar(GList lista, size_t pos) {
	GNodo *nodoAEliminar, *aux, *lib;
	
	if (pos > glist_longitud(lista) || !lista) return lista;
	
	if (pos == 0) {
		nodoAEliminar = lista;
		lista = lista->sig;
		free(nodoAEliminar);
	}
	
	aux = lista;
	for (int i = 0; i < pos - 1; i++)
		aux = aux->sig;
		
	if (!aux->sig->sig) {
		lib = aux->sig;
		aux->sig = NULL;
		
		free(lib);
	} else {
		lib = aux->sig;
		aux->sig = lib->sig;
		
		free(lib);
	}
	
	return lista;
}

/* Verificar si hay al menos 1 elemento */
size_t glist_contiene(GList lista, void *dato) {
	for (GNodo *nodo = lista; nodo != NULL; nodo = nodo->sig) {
		if (nodo->dato == dato) return 1;
	}
	
	return 0;
}
