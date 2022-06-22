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
unsigned long Perfecto(int );
void MostrarPerfectos(int , int *ct);

int main(){
	
	principal();
	return 0;
}

void principal(){
	FILE *pf = fopen("Muestra.csv","at");//Creamos el documento para los datos del analisis
	
	int ct = 0, tam = 0, pts = 20, i;
	
	for(i = 0;i<pts;i++){//Genera los puntos para el analisis
		ct = 0;
		tam = rand()%(5);// por ahora solo 4 numeros ya que no se detiene para 5
		
		MostrarPerfectos(tam, &ct);
		
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", tam, ct);//Enviamos los datos al documento
	}
	
	fclose(pf);
}

unsigned long Perfecto(int tam){//modificacion de la funcion que decide si un numero es perfecto
	int i = 0;
	unsigned long s = 0, m = 0;
	
	for(i = 1; i<tam; i++){
		m = tam%i;
		if(m == 0){
			s+=i;
		}
	}
	
	if(s == tam){
		return 1;
	}else{
		return 0;
	}
}

void MostrarPerfectos(int n, int *ct){//funcion que muestra los n primeros numeros perfectos
	unsigned long i = 0, p = 0, j = 1;(*ct)++;(*ct)++;(*ct)++;
	
	while(i < n){
		(*ct)++;
		(*ct)++;
		p = Perfecto(j);(*ct)++;
		if(p){
			(*ct)++;
			(*ct)++;
			printf(" %d ", j);
			i++;(*ct)++;
		}
		(*ct)++;
		j++;(*ct)++;
	}
	(*ct)++;
	(*ct)++;
}














