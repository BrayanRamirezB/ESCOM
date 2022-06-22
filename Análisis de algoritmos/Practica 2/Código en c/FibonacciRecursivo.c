/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
MATERIA: ANÁLISIS DE ALGORITMOS
ALUMNO: BRAYAN RAMIREZ BENITEZ
GRUPO: 3CV11
PROFESOR: LUNA BENOSO BENJAMIN
SEMESTRE: 2022-1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void principal();
unsigned long RFibonacci(int , int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int ct = 0, tam = 0, pts = 900, i;
	unsigned long f1 = 0;
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		tam = rand()%(40);//posicion de la serie, tiene como maximo 40 por el tipo de dato unsigned long
		
		f1 = RFibonacci(tam, &ct);// enviamos el numero aleatorio para que nos regrese el valor de la serie en esa posicion
		
		printf("\n fibonacci de %d es %d \n", tam, f1);
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", tam, ct);	//Enviamos los datos al documento
	}
	fclose(pf);
}

unsigned long RFibonacci(int n, int *ct){//funcion fibonacci recursiva
	if (n < 2){
		(*ct)++;
		(*ct)++;
		return n;
	}
	(*ct)++;
	return RFibonacci(n - 1, ct) + RFibonacci(n - 2, ct);	
}















