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

void principal();
void Perfecto(int , int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int ct = 0, tam = 0, pts = 900, i;
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		tam = rand()%(10000);// generamos numeros aleatorios 
		
		Perfecto(tam, &ct);// enviamos el numero aleatorio tam para verificar si es perfecto
		
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", tam, ct);//Enviamos los datos al documento
	}
	fclose(pf);
}

void Perfecto(int n, int *ct){//funcion que decide si un numero es perfecto
	int i = 0, s = 0, m = 0;(*ct)++;(*ct)++;(*ct)++;
	
	(*ct)++;
	for(i = 1; i<n; i++){
		(*ct)++;
		m = n%i;(*ct)++;
		if(m == 0){
			(*ct)++;
			(*ct)++;
			s+=i;
		}
		(*ct)++;
		(*ct)++;
	}
	(*ct)++;
	
	if(s == n){
		(*ct)++;
		(*ct)++;
		printf("\n%d es un numero perfecto.\n", n);
	}else{
		(*ct)++;
		(*ct)++;
		printf("\n%d no es un numero perfecto.\n", n);
	}
}















