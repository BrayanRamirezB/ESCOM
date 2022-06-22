#include<stdio.h>
#include<stdlib.h>
#define TAM 1024

void ImpArreglo(char A[][TAM], int n);
int TamArreglo(FILE *ENT, char* A[]);
void LeeArreglo(FILE *ENT,char* A[],int tam);
int RecogeTxt(FILE *ENT, char A[][TAM]);
void RotarFxF(char A[][TAM], int n, int *ct);


int main(){
	FILE *ENT = fopen("p3.txt", "r");
	FILE *pf = fopen("Muestra.csv","at");
	char A[TAM][TAM];
	
	int ct = 0, pts = 257, i;
	int n = RecogeTxt(ENT, A);
	
	//for(i = 2; i<pts ; i*=2){	
	//	ct = 0;
		ImpArreglo(A, n);
		RotarFxF(A, n, &ct);
		
		//printf("\n Numero de pasos: %d\n\n",ct);
		//fprintf(pf,"%d,%d\n\n", i, ct);	//Enviamos los datos al documento
	//}	
	
	//fclose(pf);
	return 0;
}

void ImpArreglo(char A[][TAM], int n){
	int i,j;
	
	for(i = 0 ; i<n ; i++){
		for(j = 0 ; j<n ; j++)
			printf("%c", A[i][j]);
		puts("");	
	}
}

int TamArreglo(FILE *ENT, char* A[]){// devuelve la cantidad de cadenas de un documento de texto
	int i;
	
	for(i=0;(fscanf(ENT,"%s",A))!=EOF;i++){
	}
	return i;
}

void LeeArreglo(FILE *ENT,char* A[],int tam){
	int i;
	  
	for(i=0;i<tam;i++) 
		fscanf(ENT,"%s",A[i] = (char*)malloc(TAM));
}

int RecogeTxt(FILE *ENT, char B[][TAM]){
	char* A[TAM];
	int n = TamArreglo(ENT, A),i,j;
	
	rewind(ENT);
	LeeArreglo(ENT,A,n);	
	rewind(ENT);
	
	for(i = 0 ; i<n ; i++){
		for(j = 0 ; j<n ; j++)
			B[i][j] = A[i][j];
	}
	fclose(ENT);
	return n;	
}

void RotarFxF(char A[][TAM], int n, int *ct){
	int i,j,z = n-1;(*ct)++;(*ct)++;(*ct)++;
	char C[n][n];(*ct)++;
	
	(*ct)++;
	for(i = 0 ; i<n ; i++){
		(*ct)++;(*ct)++;
		for(j = 0 ; j<n ; j++){
			(*ct)++;
			C[i][j] = A[j][z];(*ct)++;
		}
		(*ct)++;		
		z--;(*ct)++;
	}
	(*ct)++;



	puts("");
	
	for(i = 0 ; i<n ; i++){
		for(j = 0 ; j<n ; j++)
			printf("%c", C[i][j]);
		puts("");	
	}
}

