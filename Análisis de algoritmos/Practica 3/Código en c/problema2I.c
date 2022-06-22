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
#define TAM 6000

void principal();
void LLenaArreglo(int *A, int );
void ImprimeArreglo(int *A, int );
void InsertionSort(int *A, int );
int BI(int *A, int , int , int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int A[TAM], ct = 0, tam = 1002, pts = 100, i, indice;
	srand(time(NULL));
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		
		
		LLenaArreglo(A, tam);// Generamos un arreglo y lo llenamos con valores aletorios
		InsertionSort(A, tam);// llamamos a la funcion InsertionSort para ordenar el areglo
		puts("");
		ImprimeArreglo(A, tam);// mostramos en pantalla el arreglo
		int x = A[i]/2;//10000;//rand()%(tam);
		printf("\nx: %d\n", x);
	
		indice = BI(A, tam, x, &ct);// llamamos a la funcion BI para buscar el elemento x en el arreglo A
		printf("\nIndice: %d\n", indice);
		printf("\nNumero de pasos: %d\n\n",ct);
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

int BI(int *A, int tam, int x, int *ct){//funcion para buscar un elemento en un arreglo ordenado en bloques de 3
	int i, j, inicio = 0, fin = tam-1;
	(*ct)++;(*ct)++;(*ct)++;(*ct)++;
	
	while(inicio <= fin){
		(*ct)++;
		(*ct)++;
		i = (inicio + ((fin-inicio)/3));(*ct)++;
		j = (fin - ((fin-inicio)/3));(*ct)++;
		
		if(A[i] == x){
			(*ct)++;
			return i;(*ct)++;//el elemento se encuentra en el indice i
		}
		(*ct)++;
		if(A[j] == x){
			(*ct)++;
			return j;(*ct)++;//el elemento se encuentra en el indice j
		}else if(x < A[i]){//el elemento se encuentra antes del indice i
			(*ct)++;
			fin = i - 1;(*ct)++;
		}else if(x > A[i] && x < A[j]){//el elemento se encuentra despues del indice i y antes del indice j
			(*ct)++;
			(*ct)++;
			inicio = i + 1;(*ct)++;
			fin = j - 1;(*ct)++;
		}else if(x > A[j]){//el elemento se encuentra depues del indice j
			(*ct)++;
			inicio = j + 1;(*ct)++;
		}
		(*ct)++;
		(*ct)++;
		(*ct)++;
		(*ct)++;		
	}
	(*ct)++;
	return -1;(*ct)++;//termina el ciclo y el elemento no se encuentra en el arreglo
}

/*
Del an\'alisis a priori tenemos que el mejor caso ocurre cuando el elemento \textbf{x} se encuentra en alguna de las posiciones del arreglo con los \'indices \textbf{j} o \textbf{i} y el peor caso ocurre de acuerdo a la ecuaci\'on de recurrencia \textbf{T(n)}. Entonces para el an\'alisis a posteriori generamos arreglos con valores aleatorios entre \textbf{x}, adem\'as valores entre 12 y 512 para \textbf{tam},  estos valores los enviaremos a la funcion \textbf{BI}. El resultado de esta ejecuci\'on arroja los siguientes valores.


*/












