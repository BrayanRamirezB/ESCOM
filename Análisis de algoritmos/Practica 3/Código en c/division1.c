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

void principal();
int division1(int, int, int, int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int ct = 0, pts = 900, i;
	srand(time(NULL));
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		int n = rand()%200000;
		int q = division1(n, 1, 0, &ct);//enviamos los numeros para obtener su cociente
		
		printf("\nel cociente de %d y %d es %d\n", n, div, q);
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);	//Enviamos los datos al documento
	}
	fclose(pf);
}

int division1(int n, int div, int res, int *ct){
	int q = 0;(*ct)++;
	
	while(n >= div){
		(*ct)++;
		(*ct)++;
		n = n - div;(*ct)++;
		q = q + 1;(*ct)++;
	}
	(*ct)++;
	res = n;(*ct)++;
	(*ct)++;
	return q;
}
















