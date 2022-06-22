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
unsigned long IFibonacci(int , int *ct);

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
		tam = rand()%(40);// Generamos un numero aleatorio
		
		f1 = IFibonacci(tam, &ct);// enviamos el numero aleatorio para que nos regrese el valor de la serie en esa posicion
		
		printf("\n fibonacci de %d es %d \n", tam, f1);
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", tam, ct);	//Enviamos los datos al documento
	}
	fclose(pf);
}

unsigned long IFibonacci(int n, int *ct){//funcion fibonacci iterativa
	unsigned long s = 1, a = 0, t = 0;(*ct)++;(*ct)++;(*ct)++;
	int i = 0;(*ct)++;
	
	(*ct)++;
	for(i = 1;i <= n;i++){
		(*ct)++;
		t = a;(*ct)++;
		a = s;(*ct)++;
		s = s + t;(*ct)++;
		(*ct)++;
	}
	(*ct)++;
	(*ct)++;
	return a;
}















