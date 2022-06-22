#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265

float ConvierteC(unsigned char );
unsigned char ConvierteF(float );

int main(int argc, char *argv[]){
	
	if (argc < 3) {
		printf("Error, faltan argumentos.\n");
		printf ("Ejemplo: TDF No.muestras Salida\n", argv [0]);
		exit(0);
	}
	
	FILE *fI, *fR;
	
	fI = fopen(strcat(argv[2], "Imaginario"), "w");
	fR = fopen(strcat(argv[2], "Real"), "w");

	int nmuestras = atoi (argv [1]);
    unsigned char c;
	float datos[nmuestras];
    float arguW[nmuestras], realX[nmuestras], imagX[nmuestras], realK[nmuestras], imagK[nmuestras];
    int i, k;
    
    for (i=0; i<=(nmuestras-1); i++){//Convierte a flotante y guarda el resultado en el arreglo de datos
      scanf("%c",&c);
      datos[i] = ConvierteC(c);
	  c = '\0';
    }

    for (k=0; k<=(nmuestras-1); k++){
        realX[k]=0;
        imagX[k]=0;
      for (i=0; i<=(nmuestras-1); i++){             
        arguW[i]=((-2)*PI*i*k)/nmuestras;
        realK[i]=cos(arguW[i])*datos[i];    //está en rad
        imagK[i]=sin(arguW[i])*datos[i];    //está en rad
        realX[k]=realX[k]+realK[i];
        imagX[k]=imagX[k]+imagK[i];
      }
    }
    
    for (k=0; k<=(nmuestras-1); k++){
    	fprintf(fR,"%c\n", ConvierteF(realX[k]));
		fprintf(fI, "%c\n", ConvierteF(imagX[k]));
    	//printf("%.3f, %.3fj\n",(k+1), realX[k], imagX[k]);
	}
	
	fclose(fI);
	fclose(fR);
    return 0;
}

float ConvierteC(unsigned char c){
	//Convierte a float para no trabajar con numeros grandes
	
	if (c < 128)
		return (c/128) + 1;
	else if (c > 128)
		return (c - 127)/128;
	else
		return 0;	 
}

unsigned char ConvierteF(float f){
	//Convierte al formato original
	
	if (f < 0)
		return (f - 1)*128;
	else if (f > 0)
		return (f*128) + 127;
	else
		return 0;
}
