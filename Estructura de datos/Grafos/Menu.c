#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "ListaGen.h"
#include "ElemVertice.h"
#include "Grafos.h"

int main(){
	int opc=1;
	Grafo g=VaciaG();
	char c,u;
	//g = AgregaVertice(AgregaVertice(AgregaVertice(AgregaVertice(AgregaVertice(g,'e'),'d'),'c'),'b'),'a');
	//Puede habilitar la opcion de arriba para que el Grafo g no este vacio
	
	while(opc!=10){
		printf("Selecciona una opcion.\n");
		printf("1-)Añade un Vertice.\n2-)Muestra los Vecinos de un vertice.\n3-)Agrega una Arista.\n4-)Consulta una Arista.\n");
		printf("5-)Elimina una Arista.\n6-)Elimina un Vertice.\n7-)Es Euleriano.\n8-)Consulta Vertice.\n9-)Muestra Grafo.\n10-)Salir.\n");
		scanf("%d",&opc);
		system("cls");
		switch(opc){
			case 1:
				printf("------------------- Añade un Vertice -------------------\n");
				printf("Ingrese el caracter del vertice.\n");
				scanf(" %c",&c);
				g = AgregaVertice(g,c);
				puts("\n\n");
				break;
			case 2:
				printf("------------------- Muestra los Vecinos de un vertice -------------------\n");
				printf("Ingrese el vertice del cual quiere los vecinos.\n");
				scanf(" %c",&c);
				ImpListaL(Vecinos(g,c));
				puts("\n\n");
				break;
			case 3:
				printf("------------------- Agrega una Arista -------------------\n");
				printf("Ingrese el caracter del vertice origen.\n");
				scanf(" %c",&c);
				printf("Ingrese el caracter del vertice destino.\n");
				scanf(" %c",&u);
				g = AgregaArista(g,c,u);
				puts("\n\n");
				break;
			case 4:
				printf("------------------- Consulta una Arista -------------------\n");
				printf("Ingrese el caracter del vertice origen.\n");
				scanf(" %c",&c);
				printf("Ingrese el caracter del vertice destino.\n");
				scanf(" %c",&u);
				ImpElemArista(ObtenValorArista(g,c,u));
				puts("\n\n");
				break;
			case 5:
				printf("------------------- Elimina una Arista -------------------\n");
				printf("Ingrese el caracter del vertice origen.\n");
				scanf(" %c",&c);
				printf("Ingrese el caracter del vertice destino.\n");
				scanf(" %c",&u);
				g = EliminaArista(g,c,u);
				puts("\n\n");
				break;
			case 6:
				printf("------------------- Elimina un Vertice -------------------\n");
				printf("Ingrese el caracter del vertice.\n");
				scanf(" %c",&c);
				g = EliminaVertice(g,c);
				puts("\n\n");
				break;
			case 7:
				printf("------------------- Es Euleriano -------------------\n");
				EsEuleriano(g,0)?puts("si\n"):puts("no\n");
				puts("\n\n");
				break;
			case 8:
				printf("------------------- Consulta Vertice -------------------\n");
				printf("Ingrese el caracter del vertice.\n");
				scanf(" %c",&c);
				ImpElemVertice(ObtenValorVertice(g,c));
				puts("\n\n");
				break;
			case 9:
				printf("------------------- Muestra Grafo -------------------\n");
				puts("");
				ImpComp(g);
				puts("\n\n");
				break;
			case 10:
				printf("bis gleich!\n");
				break;
			default:
				printf("Opcion no valida.\n");									
		}
	}
}
