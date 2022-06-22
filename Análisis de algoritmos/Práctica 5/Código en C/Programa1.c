/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
MATERIA: ANÁLISIS DE ALGORITMOS
ALUMNO: BRAYAN RAMIREZ BENITEZ
GRUPO: 3CV11
PROFESOR: LUNA BENOSO BENJAMIN
SEMESTRE: 2022-1
*/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100000

void ImpArreglo(int *, int);
void LlenaArreglo(int *, int , int);
void InsertionSort(int *, int );
int PFertilizante(int *, int *, int, int , int *);

int main(){
	FILE *pf = fopen("Muestra.csv","at");
	int n = 10, r = 30, j, ct, pts = 1000, i;
	int S[TAM], C[TAM];
	
	
	
	for(i = 0; i<pts ; i++){	
		ct = 0;
		
		LlenaArreglo(C, n, r);
		printf("r = %d \nConjunto C = ", r);	
		ImpArreglo(C, n);
		j = PFertilizante(S, C, r, n, &ct);
		printf("Conjunto S = ");
		ImpArreglo(S, j);
		
		printf("\n\nNumero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);	//Enviamos los datos al documento
		n+=10;
	}	

	fclose(pf);			
	return 0;
}

void ImpArreglo(int *A, int n){//Imprime un arreglo
	int i;
	
	for(i = 0; i<n; i++)
		printf("%d ", A[i]);
	puts("");	
}

void LlenaArreglo(int *A, int n, int r){//Llena un arreglo con valores aleatorios y los ordena
	//srand(time(NULL));
	int i;
	A[0] = 0;
	
	for(i = 1;i<n;i++)
		A[i] = A[i-1] + r + 1;
	
	/*for(i = 1;i<n;i++){
		A[i] = rand()%(n+100);
	}*/
	
	InsertionSort(A, n);
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

int PFertilizante(int *S, int *C, int r, int n, int *ct){
	int f, i = 0, j = 1;(*ct)++;(*ct)++;(*ct)++;
	
	S[0] = C[0];(*ct)++;
	f = C[0] + r;(*ct)++;
	(*ct)++;
	for(i = 0; i < n; i++){
		(*ct)++;
		if(C[i] > f){
			(*ct)++;
			S[j] = C[i-1];(*ct)++;
			f = C[i-1] + r;(*ct)++;
			j++;(*ct)++;
		}
		(*ct)++;
	}
	(*ct)++;
	S[j] = C[i-1];(*ct)++;
	return j+1;	(*ct)++;
}


/*
int PFertilizante(int *S, int *C, int r, int n, int *ct){
	int f, i = 0, j = 1;//iniciamos dos contadores para los conjuntos
	
	S[0] = C[0];//El primer dia siempre se agrega al conjunto solucion
	f = C[0] + r;//Asignamos el valor de f
	
	for(i = 0; i < n; i++){
		if(C[i] > f){//preguntamos si el dia es mayor a f
			S[j] = C[i-1];//Lo agregamos al conjunto solucion
			f = C[i-1] + r;//Volvemos a asignar el valor de f
			j++;//incrementamos el contador para el conjunto solucion
		}
	}
	S[j] = C[i-1];//agregamos al conjunto solucion el ultimo
	return j+1;//regresamos el tamaño del conjunto solucion			
}
*/

