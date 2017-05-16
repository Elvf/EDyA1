#include <stdio.h>

#define MAX_HEAP 10

typedef struct _BHeap {
	int datos[MAX_HEAP];
	int nelems;
} *BHeap;

BHeap bheap_crear(void) {
	BHeap newHeap = malloc(sizeof(BHeap));
	newHeap->nelems = 0;
	
	return newHeap;
}

int bheap_es_vacio(BHeap h) {
	return (h->nelems == 0);
}

int bheap_minimo(BHeap h) {
	
}
