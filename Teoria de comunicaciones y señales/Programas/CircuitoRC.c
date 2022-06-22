#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159265359

void llenaArreglo(double*);
void Rimpulso(double* );

void main(int argc, char *argv[]){
	
	if (argc < 2) {
		printf("Error, faltan argumentos.\n");
		printf ("Ejemplo: CircuitoRC No.muestras\n");
		exit(0);
	}
	
	double x[100], h[100];
	
	llenaArreglo(x);
	llenaArreglo(h);
	Rimpulso(h);
	h[0] = 1;
	
	int i, j, y, N;
	
	N = atoi(argv[1]);	
	
	for(i = 0; i < N ;i++){
		for(j = N-1; j > 0 ;j--){
			x[j]=x[j-1];//recorremos los puntos	
		}
		scanf("%c", x[0]);//recogemos el nuevo
	}
	
	y = 0;
	
	for(i = 0; i < N ;i++){
		y = y + (x[j]*h[j]);//Sumatoria
		printf("%c\n", y);
	}
}

void llenaArreglo(double* A){
	int i;
	
	for(i = 0; i<100 ; i++)
		A[i] = 0;
}

void Rimpulso(double* A) {
    int f = 10000, t;//5000*2
    double iu = f * PI, e;

    for(t = 0; t < 100; t++) {
        int i = t;

        if (t < 0)                             
            A[i] = 0;
        else {                                
            e = exp(-iu*t);
            A[i] = iu * e;
        }
    }
}
