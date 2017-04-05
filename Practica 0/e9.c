#include <stdio.h>

void setin (int *a) {
	if (*a != 0) {
		*a = 1;
	}
}

int main (void) {
	int test = 189;
	
	setin(&test);
	
	printf("test = %d\n", test);
	
	return 0;
}
