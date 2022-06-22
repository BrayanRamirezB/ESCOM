#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Elem.h"
#include"Arreglos.h"
#include "Cadenas.h"

//Nombre: Brayan Ramirez Benitez. Grupo: 2CV12. Semestre: 2021-2. Materia: Teoria Computacional. 

int main(int argc, char *argv[]){
	FILE *ENT = fopen(*(argv+1), "r");
	Elem ttransicion[18], estador;// ttransicion es la tabla de transicion, estador es el ultimo estado al que lleva la cadena
	int opcion, opcion2, j = 1, i = tamarreglo(ENT, ttransicion);//determina la cantidad de cadenas en el documento
	char cadena[20];//cadena ingresada por el usuario
		
	rewind(ENT);//regresa el puntero al principio del documento
	leearreglo(ENT,ttransicion,i);//guarda el doc en un arreglo
	fclose(ENT);//cierra el documento
	
	//inicia el menu para el usuario
	while (j != 0){
		printf("El automata AT1.txt acepta las cadenas con tres 0's consecutivos.\n");
		printf("El automata AT2.txt acepta las cadenas que terminan en 1.\nEl automata AT3.txt acepta las cadenas que contienen 01 como subcadena.\n\n");
		printf("El alfabeto es {0,1} para todos los automatas\n\n");
		printf("Seleccione una opcion.\n\n1-) Comprobar una cadena.\n2-) Salir.\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:// inicia el proceso para comprobar si acepta la cadena
				system("cls");
				printf("Ingrese una cadena\n");
				scanf("%s", cadena);//recoge la cadena del usuario
				estador = compruebac(ttransicion,cadena);//devuelve el ultimo estado al que lleva la cadena
				EsEstadodeAcep(estador);//pregunta si es estado de aceptacion regresa un mensaje en pantalla
				printf("\nSeleccione una opcion.\n1-)Volver al menu.\n2-)Salir.\n");
				scanf("%d",&opcion2);
				if(opcion2 == 1){//regresa al menu inicial
					system("cls");
					j = 1;
				}
				else if(opcion2 == 2)// termina el programa
					j = 0;
				else{
					system("cls");//regresa al menu inicial
					printf("\nOpcion no valida-\n\n");
				}
				break;
			case 2://termina el programa
				system("cls");
				j = 0;
				printf("Gracias por usar software libre :D, 10/10");
				break;
			default://permanece en el menu
				system("cls");
				printf("Opcion no valida\n\n");
				break;
		}
	}
	return 0;
}
/*
Para abrir el programa escriba en la consola "Nombre_programa Nombre_documento.txt", Ejemplo : "PG AT1.txt" 

Instrucciones para crear nuevos automatas en txt
- todos los estados tienen un simbolo (+, -, *) seguido de una letra por ultimo el numero de estado ejemplo: *q5, -q1, +q3
- los estados de aceptacion tienen un *
- el estado inicial es -
- todos los demas llevan un +
- los vacios -0-
- si el estado inicial es de aceptacion se coloca un *
- No puede tener mas de 6 estados, sin embargo esto se puede modificar en el codigo
- si desea crear un documento recuerde llenar simpre los 6 estados
*/
