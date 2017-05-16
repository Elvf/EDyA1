#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _CDNodo {
	int dato;
	struct _CDNodo *sig;
	struct _CDNodo *ant;
} CDNodo;

typedef CDNodo *Cola;

Cola cola_crear(void) {
	return NULL;
}

int cola_es_vacia(Cola c) {
	return (c == NULL);
}

int cola_primero(Cola c) {
	assert(!cola_es_vacia(c));

	return c->dato;
}

Cola cola_encolar(Cola c, int d) {
	CDNodo *newNode = malloc(sizeof(CDNodo));
	newNode->dato = d;
	
	if (c) {
		newNode->sig = c;
		newNode->ant = c->ant;
		c->ant->sig = newNode;
		c->ant = newNode;
		
		return c;
	} else {
		newNode->sig = newNode;
		newNode->ant = newNode;
		
		return newNode;
	}
}

Cola cola_desencolar(Cola c) {
	if(!c) return NULL;
	
	/* Caso de un solo nodo */
	if(c->sig == c) {
		free(c);
		return NULL;
	} else {
		CDNodo *tmp = c->sig;
		c->ant->sig = tmp;
		tmp->ant = c->ant;
		
		free(c);
		return tmp;
	}
}

void cola_imprimir(Cola c) {
	if(!c) return;
	
	CDNodo *nodo = c->sig;
	
	printf("[%4d] ", c->dato);
	
	for(; nodo != c; nodo = nodo->sig)
		printf("[%4d] ", nodo->dato);
		
	puts(" ");
}

void cola_destruir(Cola c) {
	if(!c) return;
	
	CDNodo *nodo = c->sig;
	CDNodo *lib;
	
	while(nodo != c) {
		lib = nodo;
		nodo = nodo->sig;
		free(lib);
	}
	
	free(c);
}

int main(int argc, char *argv[]) {
	Cola c = cola_crear();
	
	c = cola_encolar(c, 4);
	c = cola_encolar(c, 7);
	c = cola_encolar(c, 5);
	c = cola_encolar(c, 1);
	
	cola_imprimir(c);
	
	printf("Primero: [%4d]\n", cola_primero(c));
	
	c = cola_desencolar(c);
	
	printf("Primero: [%4d]\n", cola_primero(c));
	
	cola_destruir(c);
	
	return 0;
}
