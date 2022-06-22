#include <stdio.h>
#include <stdlib.h>

float ConvierteC(unsigned char );
unsigned char ConvierteF(float );

int main(int argc, char const *argv[]){
	//Verifica los argumentos
	if(argc < 1)
		exit(EXIT_FAILURE);
	
	FILE *ptr = freopen(NULL,"r",stdin);
	unsigned char c, c1;
	float f;
	
	while(!feof(ptr)){
		fread(&c,sizeof(c),1,ptr);
		f = ConvierteC(c);
		c1 = ConvierteF(f);
		printf("%c\n", c1);
	}
	
	fclose(ptr);
	return 0;
}

float ConvierteC(unsigned char c){
	//Convierte a caracter y determina el valor absoluto
	
	if (c < 128)
		return ((-1*c)/128) + 1;
	else if (c > 128)
		return (c - 127)/128;
	else
		return 0;	 
}

unsigned char ConvierteF(float f){
	//Convierte al formato
	
	if (f < 0)
		return (f - 1)*128;
	else if (f > 0)
		return (f*128) + 127;
	else
		return 0;
}
