#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000

void LLenaArreglo(int *A, int );
void ImprimeArreglo(int *A, int n);
int kadane(int *A, int );

int main(){
	int A[TAM], n = 16, mt;
	int B[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	srand(time(NULL));
	
	LLenaArreglo(A, n);
	ImprimeArreglo(A, n);
	mt = kadane(A, n);
	printf("\n%d",mt);
	
	return 0;
}

void LLenaArreglo(int *A, int n){//Llena los valores de 2 arreglos con numeros aleatorios
	srand(time(NULL));
	int i;
	
	for(i = 0; i<n ;i++)
		A[i] = rand()%100-50;//
}

void ImprimeArreglo(int *A, int n){
	int i;
	
	for(i = 0; i<n ; i++)
		printf("[ %d ]",  A[i]);
}

int kadane(int *A, int n){
	int mt = 0, ma = 0,i, izq, der;
	
	for(i = 0; i<n; i++){
		ma += A[i];
		if(ma < 0){
			izq = i + 1;
			ma = 0;
		}
		if(ma > mt){
			der = i;
			mt = ma;
		}
	}

	printf("\n\n%d y %d",izq,der);
	return mt;
}
