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
void CreaDosArreglo(int *A, int *B, int n);
void ImprimeArreglo(int *A, int n);
int ProgramaUno(int *A, int *B, int n, int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int A[TAM], B[TAM], tam = 10, ct = 0, i, pts = 20, decimal = 0;
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		CreaDosArreglo(A, B, tam);// Llenamos los valores de ambos arreglos
		ImprimeArreglo(A, tam);//mostramos un arreglo
		puts("");
		ImprimeArreglo(B, tam);//mostramos un arreglo
		puts("");
		
		decimal = ProgramaUno(A, B, tam, &ct);//Llamamos a la funcion para enviarle los dos arreglos y que nos devuelva el resultado de aplicar un & en decimal
		
		printf("\n Numero en decimal: %d\n",decimal);
		printf("\n Numero de pasos: %d\n",ct);
		fprintf(pf,"%d,%d\n\n", tam, ct);//Enviamos los datos al documento
		tam+=1;	//incrementamos en 1 el tamaño de los arreglos
	}
	fclose(pf);
}

void CreaDosArreglo(int *A, int *B, int n){//Llena los valores de 2 arreglos con numeros aleatorios
	srand(time(NULL));
	int i;
	
	for(i = 0; i<n ;i++)
		A[i] = rand()%2;
		
	for(i = 0; i<n ;i++)
		B[i] = rand()%2;	
}

void ImprimeArreglo(int *A, int n){//muestra en pantalla un arreglo.
	int i;
	
	for(i = 0; i<n ; i++)
		printf("[ %d ]",  A[i]);
}

int ProgramaUno(int *A, int *B, int n, int *ct){//Funcion para el algoritmo del problema 1, recibe 2 arreglos y devuelve el numero en decimal despues de aplicar un &
	int decimal = 0;(*ct)++;
	int i = 0;(*ct)++;
	int potencia = 1;(*ct)++;
	(*ct)++;
	for(i = n-1; i>=0 ; i--){//permite recorrer ambos arreglos para aplicar la operacion &
		(*ct)++;
		if(A[i]&B[i]){//comprueba si el resultado de & es 1 o 0
			(*ct)++;
			(*ct)++;
			decimal+=potencia;//suma las potencias ativas de 2 en el resultado de aplicar & a cada posicion de los arreglos
		}
		(*ct)++;
		(*ct)++;
		potencia = potencia*2;//incrementa la potencia de 2 		
	}
	(*ct)++;
	(*ct)++;
	return decimal;//regresa el valor en decimal
}

/*

for(i = 0; i<n ; i++){
		decimal = ((A[i]&B[i])*pow(2,n-1-i)) + (decimal);
	}
*/

















