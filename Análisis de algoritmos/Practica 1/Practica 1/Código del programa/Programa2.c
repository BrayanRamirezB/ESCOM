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
#define TAM 1000

void principal();
void RellenaFib(int *A, int n);
int Euclides(int m, int n, int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");
	
	int A[TAM], ct = 0, i = 0, m = 0, n = 0, pts = 30, mcd = 0, tam = 100;
	
	RellenaFib(A, tam);
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		m = rand()%(TAM); // A[i];;     llenamos los datos de m con un numero random o un valor de la sucesion de fibonacci
		n = rand()%(TAM); // A[i+1];   llenamos los datos de n con un numero random o un valor de la sucesion de fibonacci
				
		mcd = Euclides(m, n, &ct);// llamamos a la funcion Euclides para que nos devuelva el MCD de m y n
		
		printf("\n MCD de los numeros %d y %d : %d\n", m, n, mcd);
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);	//Enviamos los datos al documento
	}
	fclose(pf);
}

int Euclides(int m, int n, int *ct){//Funcion para el algoritmo del problema 2, recibe 2 variables y devuelve el MCD de las variables
	int r = 0;(*ct)++;
	(*ct)++;
	while(n != 0){
		(*ct)++;
		r = m%n;(*ct)++;
		m = n;(*ct)++;
		n = r;(*ct)++;
	}
	(*ct)++;
	(*ct)++;
	return m;
}

void RellenaFib(int *A, int n){//Funcion que nos regresa los valores de la sucesion de fibonacci en un arreglo
	int s, i, aux = 0, a = 1;
	
	A[0] = 1;
	for(i = 1; i<n ;i++){
		s = a + aux;
		A[i] = s;
		aux = a;
		a = s;		
	}
}

 
