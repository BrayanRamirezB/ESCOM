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
#define TAM 1000000

void Principal();
int RecogeTxt(FILE *, char *);
int Maximo(int , int );
int ComparaCadenas(char *, char *, int , int );

int main() {
    
    Principal();
    
    return 0;
}

void Principal(){
	FILE *f1 = fopen("c1.txt","rt");
	FILE *f2 = fopen("c6.txt","rt");
    char X[TAM], Y[TAM];
	
	int m = RecogeTxt(f1, X), n = RecogeTxt(f2, Y);//Recogemos los archivos de texto y obtenemos su tamaño
	printf("X: ");
	puts(X);//Imprimimos el 1er documento txt
	puts("");
	printf("Y: ");
	puts(Y);//Imprimimos el 2do documento txt
	puts("");
	printf("Tiene un parecido de %d %%", ComparaCadenas(X,Y,m,n));//mostramos el porcentaje
	
	
	fclose(f1);fclose(f2);
}

int RecogeTxt(FILE *f, char *A){
	int i = 0;
    char c;

    while((c=fgetc(f))!=EOF){
        if((c != '\n')&&(c != ' ')&&(c != '\t')&&(c != '\v')&&(c != '\f')&&(c != '\r')&&(c != '\0')){
			A[i] = c;
			i++;
		}			
    }
	
	return i;
}

int Maximo(int a, int b){
	if(a > b)
		return a;
	else
		return b;	 
}


int ComparaCadenas(char *X, char *Y, int m, int n){//El algoritmo recibe los tamaños
	char C[m+1][n+1];//	creamos una matriz para la tabla C					
	int i, j;//Iniciamos los indices
	
	for(i = 1; i<=m; i++)//llenamos la primera fila con 0
		C[i][0] = 0;
	for(j = 0; j<=n; j++)//lenamos la primera columna con 0
		C[0][j] = 0;
		
	for(i=1; i<=m; i++){//recorremos filas
		for(j=1;j<=n;j++){//recorremos columnas
			if(X[i-1] == Y[j-1])//Los elementos en comun de ambos arreglos (X,Y)
				C[i][j] = C[i-1][j-1] + 1;
			else if(C[i-1][j]>=C[i][j-1])//Elementos diferentes caso 1
				C[i][j] = C[i-1][j];
			else//elementos diferentes caso 2
				C[i][j] = C[i][j-1];	
		}
	}
	return (C[m][n]*100)/Maximo(m,n);//Calculamos y regresamos el % de parecido		
}

//Observamos que todos los programas tienen un porcentaje de parecido por la estructura


