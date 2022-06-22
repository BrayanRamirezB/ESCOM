#include<stdio.h>
#include<stdlib.h>
#define TAM 512

void ImpArreglo(char A[][TAM], int n);
int TamArreglo(FILE *ENT, char* A[]);
void LeeArreglo(FILE *ENT,char* A[],int tam);
int RecogeTxt(FILE *ENT, char A[][TAM]);
void RotarArreglo(char A[][TAM], char C[][TAM],int f, int c, int n, int *ct, int v);

int main(){
	FILE *ENT = fopen("p4.txt", "r");
	FILE *pf = fopen("Muestra.csv","at");
	char A[TAM][TAM],C[TAM][TAM];
	int n = RecogeTxt(ENT, A),ct = 0, pts = 257, i;
	
	for(i = 2; i<pts ; i*=2){	
		ct = 0;
		ImpArreglo(A,n);
		RotarArreglo(A, C, i, i, i, &ct, i);
		puts("");
		ImpArreglo(C, i);
		printf("\n\nNumero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", i, ct);	//Enviamos los datos al documento
	}	
	
	fclose(ENT);
	fclose(pf);	
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
	
	for(i = 0 ; i<n ; i++){
		for(j = 0 ; j<n ; j++)
			B[i][j] = A[i][j];
	}

	return n;	
}

void RotarArreglo(char A[][TAM], char C[][TAM], int f, int c, int n, int *ct, int v){
	if(n == 2){
		(*ct)++;
		int aux = A[f-2][c-2];	(*ct)++;		
		A[f-2][c-2] = A[f-2][c-1];(*ct)++;
		A[f-2][c-1] = A[f-1][c-1];(*ct)++;
		A[f-1][c-1] = A[f-1][c-2];(*ct)++;
		A[f-1][c-2] = aux;(*ct)++;
		if(f<=(v/2)){
			(*ct)++;
			C[f-2][c-2] = A[c-2][v-f+1];(*ct)++;
			C[f-2][c-1] = A[c-1][v-f+1];(*ct)++;
			C[f-1][c-2] = A[c-2][v-f];(*ct)++;
			C[f-1][c-1] = A[c-1][v-f];	(*ct)++;
		}else{
			C[f-2][c-2] = A[c-2][v-f];(*ct)++;
			C[f-2][c-1] = A[c-2][v-f+1];(*ct)++;
			C[f-1][c-2] = A[c-1][v-f];(*ct)++;
			C[f-1][c-1] = A[c-1][v-f+1];(*ct)++;
		}(*ct)++;
	}else{
		RotarArreglo(A,C,f-(n/2),c-(n/2),n/2, ct,v);(*ct)++;
		RotarArreglo(A,C,f-(n/2),c,n/2,ct,v);(*ct)++;
		RotarArreglo(A,C,f,c-(n/2),n/2,ct,v);(*ct)++;
		RotarArreglo(A,C,f,c,n/2,ct,v);(*ct)++;
	}
	(*ct)++;
}

/*
void RotarArreglo(char A[][TAM], char C[][TAM], int f, int c, int n, int v){//funcion sin el parametro ct
	if(n == 2){//Vence (Resolvemos el caso base, cuando el mamaño es de 2x2, rotamos la matriz)
		int aux = A[f-2][c-2];//rotamos la matriz 2x2			
		A[f-2][c-2] = A[f-2][c-1];
		A[f-2][c-1] = A[f-1][c-1];
		A[f-1][c-1] = A[f-1][c-2];
		A[f-1][c-2] = aux;
		
		if(f<=(v/2)){//Combina (Copiamos los valores de la matriz rotada en otra mitad ordenandolos de tal manera que la Matriz A este rotada 90°)
			C[f-2][c-2] = A[c-2][v-f+1];//ordena la mitad superior
			C[f-2][c-1] = A[c-1][v-f+1];
			C[f-1][c-2] = A[c-2][v-f];
			C[f-1][c-1] = A[c-1][v-f];	
		}else{
			C[f-2][c-2] = A[c-2][v-f];//ordena la mitad inferior
			C[f-2][c-1] = A[c-2][v-f+1];
			C[f-1][c-2] = A[c-1][v-f];
			C[f-1][c-1] = A[c-1][v-f+1];
		}
	}else{//Divide (dividimos la matriz a la mitad, es decir en cuatro partes)
		RotarArreglo(A,C,f-(n/2),c-(n/2),n/2, ct,v);
		RotarArreglo(A,C,f-(n/2),c,n/2,ct,v);
		RotarArreglo(A,C,f,c-(n/2),n/2,ct,v);
		RotarArreglo(A,C,f,c,n/2,ct,v);
	}
}

*/





