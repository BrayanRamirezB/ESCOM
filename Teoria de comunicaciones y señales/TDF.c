#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265

int main(int argc, char *argv[]){
	
	if (argc < 3) {
		printf("Error faltan argumentos.\n");
		printf ("Ejemplo TDF No.muestras Salida\n", argv [0]);
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
    
    for (i=0; i<=(nmuestras-1); i++){
      scanf("%c",&c);
      datos[i] = c/nmuestras;
	  c = '\0';
    }

    for (k=0; k<=(nmuestras-1); k++){
        realX[k]=0;
        imagX[k]=0;
      for (i=0; i<=(nmuestras-1); i++){             
        arguW[i]=((-2)*PI*i*k)/nmuestras;
        realK[i]=cos(arguW[i])*datos[i];    
        imagK[i]=sin(arguW[i])*datos[i];    
        realX[k]=realX[k]+realK[i];
        imagX[k]=imagX[k]+imagK[i];
      }
    }
    
    for (k=0; k<=(nmuestras-1); k++){
    	fprintf(fR,"%c\n", realX[k]);
		fprintf(fI, "%c\n", imagX[k]);	
	}
	
	fclose(fI);
	fclose(fR);
    return 0;
}


