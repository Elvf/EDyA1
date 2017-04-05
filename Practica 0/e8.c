#include <stdio.h>

typedef struct _punto {
	float x;
	float y;
} punto;

punto medio (punto a, punto b) {
	punto puntoMedio;
	
	puntoMedio.x = (float)((a.x + b.x) / 2);
	puntoMedio.y = (float)((a.y + b.y) / 2);
	
	return puntoMedio;
}

int main (void) {
  punto a, b, med;
  
  a.x = -4.3f;
  a.y = 3.1f;
  
  b.x = 6.45f;
  b.y = -3.5f;
  
  med = medio(a, b);
  
  printf("El punto medio entre a y b es (%f, %f)\n", med.x, med.y);
  
  return 0;
}
