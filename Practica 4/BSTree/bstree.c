#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bstree.h"

BSTree bstree_insertar(BSTree arbol, int dato) {
  BSNode *newNode = malloc(sizeof(BSNode));
  newNode->dato = dato;
  newNode->left = NULL;
  newNode->right = NULL;
  
  if (!arbol) {
    return newNode;
  }
  
  /* Debemos insertar el dato donde corresponda */
  if (dato < arbol->dato)
    arbol->left = bstree_insertar(arbol->left, dato);
  else if (dato > arbol->dato)
    arbol->right = bstree_insertar(arbol->right, dato);
    
  return arbol;
}

static BSNode *menor_nodo(BSNode *nodo) {
  BSNode *actual = nodo;
  
  while(nodo->left != NULL) {
    nodo = nodo->left;
  }
  
  return nodo;
}

BSTree bstree_eliminar(BSTree arbol, int dato) {
  if (!arbol) return NULL;
  
  BSNode *cursor;
  
  /* Si el dato es menor, debemos elminar del subarbol izquierdo,
   * en caso contrario eliminamos del derecho */
  if (dato < arbol->dato) {
    arbol->left = bstree_eliminar(arbol->left, dato);
  } else if (dato > arbol->dato) {
    arbol->right = bstree_eliminar(arbol->right, dato);
  } else {
    /* Si el arbol contiene el dato que estamos buscando, debemos
     * plantearnos casos si el subarbol donde estamos tiene o no hijos
     * que debemos reacomodar para que el arbol mantenga su forma de
     * Arbol Binario de Busqueda */
    if (!arbol->left) {
      cursor = arbol->right;
      free(arbol);
      arbol = cursor;
    } else if (!arbol->right) {
      cursor = arbol->left;
      free(arbol);
      arbol = cursor;
    } else {
      cursor = arbol->right;
      BSNode *padre = NULL;
      
      while (cursor->left) {
        padre = cursor;
        cursor = cursor->left;
      }
      
      arbol->dato = cursor->dato;
      
      if (padre) {
        padre->left = bstree_eliminar(padre->left, padre->left->dato);
      } else {
        arbol->right = bstree_eliminar(arbol->right, arbol->right->dato);
      }
    }
  }
  
  return arbol;
}

int bstree_contiene(BSTree arbol, int dato) {
  if (!arbol) return 0;
  
  /* Si el dato esta en la raiz, devolvemos true */
  if (dato == arbol->dato) return 1;
  
  /* Si el dato es menor, nos redireccionamos al subarbol izquierdo.
   * En caso contrario, vemos is esta en el subarbol derecho. */
  if (dato < arbol->dato) {
    bstree_contiene(arbol->left, dato);
  } else if (dato > arbol->dato) {
    bstree_contiene(arbol->right, dato);
  }
  
  /* Caso por defecto, si no se ejecuta nada de lo de arriba significa
   * que el dato no esta en el arbol */
  return 0;
}

unsigned int bstree_nelems(BSTree arbol) {
  if (arbol) {
    return (1 + bstree_nelems(arbol->left) + bstree_nelems(arbol->right));
  } else return 0;
}

unsigned int bstree_altura(BSTree arbol) {
  int profundidadDerecha, profundidadIzquierda;
  
  if (!arbol) {
    return 0;
  } else {
    profundidadIzquierda = bstree_altura(arbol->left);
    profundidadDerecha = bstree_altura(arbol->right);
    
    if (profundidadIzquierda > profundidadDerecha) {
      return (profundidadIzquierda + 1);
    } else {
      return (profundidadDerecha + 1);
    }
  }
}

void bstree_recorrer(BSTree arbol, BTreeOrdenDeRecorrido orden,
                     FuncionVisitante visitar) {
  if (!arbol) return;
  
  if (orden == BTREE_RECORRIDO_IN) {
    bstree_recorrer(arbol->left, orden, visitar);
    visitar(arbol->dato);
    bstree_recorrer(arbol->right, orden, visitar);
  } else if (orden == BTREE_RECORRIDO_POST) {
    bstree_recorrer(arbol->left, orden, visitar);
    bstree_recorrer(arbol->right, orden, visitar);
    visitar(arbol->dato);
  } else if (orden == BTREE_RECORRIDO_PRE) {
    visitar(arbol->dato);
    bstree_recorrer(arbol->left, orden, visitar);
    bstree_recorrer(arbol->right, orden, visitar);
  } else {
    /* Osas pasarme un valor de orden que no es valido, EH?! */
    return;
  }
}

/**
 * Ejercicio 10
 */
static void imprimir_entero(int a) {
  printf("%d ", a);
}
 
void bstree_imprimir(BSTree arbol) {
  bstree_recorrer(arbol, BTREE_RECORRIDO_IN, imprimir_entero);
  puts("");
}

/**
 * Balancear
 */
static void bstree_a_array(BSTree arbol, int arr[], int *pos) {
  if (!arbol) return;
  
  bstree_a_array(arbol->left, arr, pos);
  arr[*pos] = arbol->dato;
  (*pos)++;
  bstree_a_array(arbol->right, arr, pos);
}

static BSTree array_a_bstree(int arr[], int inicio, int fin) {
  if (inicio > fin)
    return NULL;
    
  /* Buscamos el elemento del medio */
  int medio = (inicio + fin) / 2;
  
  /* Insertamos el elemento en un arbol nuevo */
  BSNode *raiz = NULL;
  raiz = bstree_insertar(raiz, arr[medio]);
  
  /* Construimos los subarboles recursivamente */
  raiz->left = array_a_bstree(arr, inicio, medio - 1);
  raiz->right = array_a_bstree(arr, medio + 1, fin);
  
  return raiz;
}

BSTree bstree_balancear(BSTree arbol) {
  if (!arbol) return NULL;
  
  unsigned int nelems = bstree_nelems(arbol);
  int arr[nelems];
  int *pos;
  *pos = 0;
  
  bstree_a_array(arbol, arr, pos);
  
  arbol = array_a_bstree(arr, 0, nelems - 1);
  
  return arbol;
}

int bstree_minimo(BSTree arbol) {
  BSNode *nodo = arbol;
  
  while (nodo->left != NULL) {
    nodo = nodo->left;
  }
    
  return nodo->dato;
}

static int *acceder_recorrido(BSTree arbol, int indice, int* cur) {
  if(!arbol) return NULL;
  
  acceder_recorrido(arbol->left, indice, cur);
  
  if (indice == *cur) {
    return &(arbol->dato);
  } else {
    (*cur)++;
  }
  
  acceder_recorrido(arbol->right, indice, cur);
}

/* El i-esimo elemento del in-order */
int bstree_acceder(BSTree arbol, int indice) {
  int cur = 0;
  int *elem = acceder_recorrido(arbol, indice, &cur);
  assert(elem);
  
  return *elem;
}
