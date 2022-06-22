#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	unsigned char c;
	int n = 0, i;
	
	if(argc < 1)
		printf("Numero de muestras\n");
	
	n = atoi(argv[1]);	
	
	for(i = 0; i < n; i++){
		scanf("%c", &c);
		printf("Caracter: %c, Decimal: %d, Hexadecimal: %.2x \n", c, c, c);
		fflush(stdin);
	}
	
	return 0;
}
