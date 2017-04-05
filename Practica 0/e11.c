#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _contacto {
	char nombre[100];
	char telefono[100];
	unsigned int edad;
} contacto;

float prom (contacto *list, int size) {
	int sumaEdades = 0, i;
  float promedio;
  
  for (i = 0; i < size; i++) {
    sumaEdades = sumaEdades + list[i].edad;
  }
  
  promedio = (float)(sumaEdades / size);
  
  return promedio;
}

int main (void) {
  contacto *lista = malloc(4 * sizeof(contacto));
  float promedio;
  
  strcpy(lista[0].nombre, "Syd Barret");
  strcpy(lista[0].telefono, "7864453");
  lista[0].edad = 44;
  
  strcpy(lista[1].nombre, "Roger Waters");
  strcpy(lista[1].telefono, "7869208");
  lista[1].edad = 71;
  
  strcpy(lista[2].nombre, "Nick Mason");
  strcpy(lista[2].telefono, "7860012");
  lista[2].edad = 59;
  
  strcpy(lista[3].nombre, "David Gilmour");
  strcpy(lista[3].telefono, "7863204");
  lista[3].edad = 82;
  
  promedio = prom(lista, 4);
  
  printf("El promedio de las edades es %f\n", promedio);
  
  return 0;
}
