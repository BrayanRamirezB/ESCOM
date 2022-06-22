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
#define TAM 10000

void principal();
void LLenaArreglo(int *A, int );
void ImprimeArreglo(int *A, int );
void InsertionSort(int *A, int );
int BR(int *A, int , int , int , int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int A[TAM], ct = 0, tam = 12, pts = 900, i, indice;
	srand(time(NULL));
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;

		LLenaArreglo(A, tam);
		InsertionSort(A, tam);
		puts("");
		ImprimeArreglo(A, tam);
		puts("");
		
		int x = A[i]/2;
		printf("\nx: %d\n", x);
		
		indice = BR(A, 0, tam - 1, x, &ct);
		printf("\nIndice: %d\n", indice);
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", tam, ct);	//Enviamos los datos al documento
		tam+=10;
	}
	fclose(pf);
}

void LLenaArreglo(int *A, int n){//Llena los valores de 2 arreglos con numeros aleatorios
	srand(time(NULL));
	int i;
	
	for(i = 0; i<n ;i++)
		A[i] = rand()%(n+10);//
}


void ImprimeArreglo(int *A, int n){//muestra en pantalla un arreglo.
	int i;
	
	for(i = 0; i<n ; i++)
		printf("[ %d ]",  A[i]);
}

void InsertionSort(int *A, int n){// ordena un arreglo
	int i, j, key;
	
	for(i = 1; i<n ; i++){
		key = A[i];
		j = i-1;
		
		while(j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

int BR(int *A, int inicio, int fin, int x, int *ct){//funcion para buscar un elemento en un arreglo ordenado en bloques de 3
	int i = (inicio + ((fin-inicio)/3));(*ct)++;
	int j = (fin - ((fin-inicio)/3));(*ct)++;
	
	if(inicio > fin){
		(*ct)++;
		(*ct)++;
		return -1;//el elemento no se encuentra en el arreglo
	}
	(*ct)++;
	if(A[i] == x){
		(*ct)++;
		(*ct)++;
		return i;//el elemento se encuentra en el indice i
	}
	(*ct)++;
	if(A[j] == x){
		(*ct)++;
		(*ct)++;
		return j;//el elemento se encuentra en el indice j
	}
	else if(x < A[i]){
		(*ct)++;
		(*ct)++;
		return BR(A, inicio, i-1, x, ct);//el elemento se encuentra antes del indice i
	}else if(x > A[i] && x < A[j]){
		(*ct)++;
		(*ct)++;
		return BR(A, i+1, j-1, x, ct);//el elemento se encuentra despues del indice i y antes del indice j
	}else if(x > A[j]){
		(*ct)++;
		(*ct)++;
		return BR(A, j+1, fin, x, ct);//el elemento se encuentra depues del indice j
	}
	(*ct)++;(*ct)++;(*ct)++;(*ct)++;
}







