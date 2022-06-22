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
int division2(int, int, int, int *ct);

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
		int q = division2(n, 1, 0, &ct);//enviamos los numeros para obtener su cociente
		
		printf("\nel cociente de %d y %d es %d\n", n, div, q);
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);	//Enviamos los datos al documento
	}
	fclose(pf);
}

int division2(int n, int div, int res, int *ct){
	int dd = div;(*ct)++;
	int q = 0;(*ct)++;
	int r = n;(*ct)++;
	
	while(dd <= n){
		(*ct)++;
		(*ct)++;
		dd = 2*dd;
	}(*ct)++;
	while(dd > div){
		(*ct)++;
		dd = dd/2;(*ct)++;
		q = 2*q;(*ct)++;
		if(dd <= r){
			(*ct)++;
			r = r - dd;(*ct)++;
			q = q + 1;(*ct)++;
		}
		(*ct)++;
	}(*ct)++;
	(*ct)++;
	return q;
}






