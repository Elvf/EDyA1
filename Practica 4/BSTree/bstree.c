#include <stdlib.h>
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
  
  BSNode *temp;
  
  /* Buscamos el subarbol que corresponda */
  if (dato < arbol->dato)
    arbol = bstree_eliminar(arbol->left, dato);
  else if (dato > arbol->dato) {
    arbol = bstree_eliminar(arbol->right, dato);
  else {
    if (!arbol->left) {
      temp = arbol->right;
      free(arbol);
      return temp;
    } else if (!arbol->right) {
      temp = arbol->left;
      free(arbol);
      return temp;
    }
    
    /* Buscamos el menor en el subarbol derecho */
    temp = menor_nodo(arbol->right);
    
    /* Copiamos el dato del menor nodo del subarbol derecho a la raiz
     * actual */
    arbol->dato = temp->dato;
    
    /* Continuamos con la eliminacion */
    arbol->right = bstree_eliminar(arbol->right, dato);
  }
  
  return arbol;
}

int bstree_contiene(BSTree arbol, int dato);

unsigned int bstree_nelems(BSTree arbol);

unsigned int bstree_altura(BSTree arbol);

void bstree_recorrer(BSTree arbol, FuncionVisitante visitar);
