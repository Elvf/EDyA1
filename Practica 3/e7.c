#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_HEAP 15

#define parent(x) (x - 1) / 2
#define lchild(x) x * 2 + 1
#define rchild(x) x * 2

typedef struct _BHeap {
	int datos[MAX_HEAP];
	int nelems;
} *BHeap;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

BHeap bheap_crear(void) {
	BHeap newHeap = malloc(sizeof(BHeap));
	newHeap->nelems = 0;
	
	return newHeap;
}

int bheap_es_vacio(BHeap h) {
	return (h->nelems == 0);
}

int bheap_minimo(BHeap h) {
	assert(!bheap_es_vacio(h));
  
  return (h->datos[0]);
}

void bheap_insertar(BHeap h, int d) {
  int i;
  
  if(!h) {
    return;
  } else if(h->nelems == MAX_HEAP - 1) {
    return;
  }
  
  if(h->nelems == 0) {
    h->datos[0] = d;
    h->nelems++;
    return;
  }
  
  i = (h->nelems)++;
  
  while(i && d < h->datos[parent(i)]) {
    h->datos[i] = h->datos[parent(i)];
    i = parent(i);
  }
  
  h->datos[i] = d;
}

/**
 * Ejercicio 9
 */
void heapify(BHeap h, int i) {
  int smallest = (lchild(i) < h->nelems && h->datos[lchild(i)] < h->datos[i]) ? lchild(i) : i;
  
  if(rchild(i) < h->nelems && h->datos[rchild(i)] < h->datos[smallest]) {
    smallest = rchild(i);
  }
  
  if(smallest != i) {
    swap(&(h->datos[i]), &(h->datos[smallest]));
    heapify(h, smallest);
  }
}

void bheap_eliminar_minimo(BHeap h) {
  if(h->nelems) {
    h->datos[0] = h->datos[--(h->nelems)];
    heapify(h, 0);
  } else return;
}

void bheap_imprimir(BHeap h) {
  int i;
  
  for(i = 0; i < h->nelems; i++) {
    printf("%4d ", h->datos[i]);
  }

  puts(" ");
}

/**
 * Ejercicio 10
 */
BHeap bheap_merge(BHeap h1, BHeap h2) {
  if (bheap_es_vacio(h1))
    return h2;
  else if (h1->nelems == MAX_HEAP)
    return h1;
    
  BHeap output = bheap_crear();
  int i, totalElems;
  
  if (h1->nelems + h2->nelems == MAX_HEAP)
    totalElems = MAX_HEAP;
  else totalElems = h1->nelems + h2->nelems;
  
  /* Copiamos todos los elementos a un nuevo heap...
   * Lamentablemente, esta es la unica forma "eficiente" que se
   * me ocurrio para hacerlo. Practicamente corre en O(2 log (k)) */
  for(i = 0; i < h1->nelems; i++) {
    bheap_insertar(output, h1->datos[i]);
  }
  
  for(i = 0; i < totalElems - h1->nelems; i++) {
    bheap_insertar(output, h2->datos[i]);
  }
  
  heapify(output, 0);
  
  return output;
}

int main(int argc, char *argv[]) {
  BHeap hippy = bheap_crear();
  BHeap hip = bheap_crear();
  
  bheap_insertar(hippy, 1);
  bheap_insertar(hippy, 7);
  bheap_insertar(hippy, 5);
  bheap_insertar(hippy, 4);
  bheap_insertar(hippy, 2);
  
  //bheap_insertar(hip, -3);
  //bheap_insertar(hip, 4);
  //bheap_insertar(hip, 0);
  //bheap_insertar(hip, 1);
  //bheap_insertar(hip, -4);
  
  printf("Nelems: %d\n\n", hippy->nelems);
  
  bheap_imprimir(hippy);
  
  bheap_eliminar_minimo(hippy);
  bheap_eliminar_minimo(hippy);
  
  bheap_imprimir(hippy);
  
  bheap_insertar(hippy, 1);
  
  bheap_imprimir(hippy);
  
  return 0;
}
