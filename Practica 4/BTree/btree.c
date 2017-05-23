#include "btree.h"
#include "tqueue.h"
#include <stdio.h>
#include <stdlib.h>

BTree btree_crear() {
  return NULL;
}

void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(BTNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Ejercicio 3
 */
int btree_sum(BTree arbol) {
  if (arbol) {
    return (arbol->dato + btree_sum(arbol->left) + btree_sum(arbol->right));
  } else {
    return 0;
  }
}

int btree_nodos(BTree arbol) {
  if (arbol) {
    return (1 + btree_nodos(arbol->left) + btree_nodos(arbol->right));
  } else return 0; 
}

int btree_altura(BTree arbol) {
  int profundidadDerecha, profundidadIzquierda;
  
  if (!arbol) {
    return 0;
  } else {
    profundidadIzquierda = btree_altura(arbol->left);
    profundidadDerecha = btree_altura(arbol->right);
    
    if (profundidadIzquierda > profundidadDerecha) {
      return (profundidadIzquierda + 1);
    } else {
      return (profundidadDerecha + 1);
    }
  }
}

/**
 * Ejercicio 4
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
  if (arbol) {
    
    if (orden == BTREE_RECORRIDO_IN) {
      btree_recorrer(arbol->left, orden, visit);
      visit(arbol->dato);
      btree_recorrer(arbol->right, orden, visit);
    } else if (orden == BTREE_RECORRIDO_POST) {
      btree_recorrer(arbol->left, orden, visit);
      btree_recorrer(arbol->right, orden, visit);
      visit(arbol->dato);
    } else if (orden == BTREE_RECORRIDO_PRE) {
      visit(arbol->dato);
      btree_recorrer(arbol->left, orden, visit);
      btree_recorrer(arbol->right, orden, visit);
    } else return;
  
  } else return;
}

/**
 * Ejercicio 5
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,
                          FuncionVisitanteExtra visit, void *extra) {
  if (arbol) {
    
    if (orden == BTREE_RECORRIDO_IN) {
      btree_recorrer_extra(arbol->left, orden, visit, extra);
      visit(arbol->dato, extra);
      btree_recorrer_extra(arbol->right, orden, visit, extra);
    } else if (orden == BTREE_RECORRIDO_POST) {
      btree_recorrer_extra(arbol->left, orden, visit, extra);
      btree_recorrer_extra(arbol->right, orden, visit, extra);
      visit(arbol->dato, extra);
    } else if (orden == BTREE_RECORRIDO_PRE) {
      visit(arbol->dato, extra);
      btree_recorrer_extra(arbol->left, orden, visit, extra);
      btree_recorrer_extra(arbol->right, orden, visit, extra);
    }
    
  }
}

/* Sumar nodos */
static void sumar_nodos(int dato, void *extra) {
  *((int *)extra) += dato;
}

int btree_sum_extra(BTree arbol) {
  int sumaTotal = 0;
  
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_PRE, sumar_nodos, &sumaTotal);
  
  return sumaTotal;
}

/* Contar nodos */
static void contar_nodos(int data, void *extra) {
  *((int *)extra) += 1;
}

int btree_nodos_extra(BTree arbol) {
  int contador = 0;
  
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN, contar_nodos, &contador);
  
  return contador;
}

/* La funcion que calcula la altura no se puede rehacer con el recorrido
 * con dato extra porque el recorrido va solamente hacia abajo y para
 * calcular la altura necesito comparar entre los subarboles */

/**
 * Ejercicio 6
 */
void btree_recorrer_bfs(BTree arbol, FuncionVisitante visit) {
  TQueue cola = NULL;
  BTNodo *temp = arbol;
  
  if(!arbol) return;
  
  cola = tqueue_encolar(cola, arbol);
  
  while(cola != NULL) {
    visit(cola->currentNode->dato);
    
    if(cola->currentNode->left) {
      cola = tqueue_encolar(cola, cola->currentNode->left);
    }
    
    if(cola->currentNode->right) {
      cola = tqueue_encolar(cola, cola->currentNode->right);
    }
    
    cola = tqueue_desencolar(cola);
  }
  
  puts(" ");
}
