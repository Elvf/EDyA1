#include <stdio.h>
#include <stdlib.h>

typedef struct _contacto {
	char nombre[100];
	char telefono[100];
	unsigned int edad;
} contacto;

void actualizarEdad (contacto *a) {
	printf("Introduzca una nueva edad para el Contacto: ");
	scanf("%ud", &(a->edad));
}

contacto crearContacto (void) {
	contacto newContact;
  
  printf("Nombre del Contacto: ");
  scanf("%s", newContact.nombre);
  
  printf("Telefono del Contacto: ");
  scanf("%s", newContact.telefono);
  
  printf("Edad del Contacto: ");
  scanf("%ud", &newContact.edad);
  
  return newContact;
}

int main (void) {
  contacto contact = crearContacto();
  
  printf("\nCONTACTO\nNombre: %s\nTelefono: %s\nEdad: %d\n\n", contact.nombre, contact.telefono, contact.edad);
  
  actualizarEdad(&contact);
  
  printf("\nCONTACTO ACTUALIZADO\nNombre: %s\nTelefono: %s\nEdad: %d\n", contact.nombre, contact.telefono, contact.edad);
  
  return 0;
}
