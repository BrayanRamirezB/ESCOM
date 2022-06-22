#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "ListaGen.h"

int main(){
	ListaGen lg1,lg2,lg3,lg4;

	lg2=ConsElem(3,ConsElem(4,ConsElem(5,VaciaG()))); 
	lg3=ConsElem(8,ConsElem(9,VaciaG())); 
	lg4=ConsElem(7,ConsLista(lg3,ConsElem(10,VaciaG()))); 
	lg1=ConsLista(lg2,ConsElem(2,ConsLista(lg2,ConsElem(6,ConsLista(lg4,ConsElem(11,ConsElem(12,VaciaG()))))))); 

	//EsVaciaG(lg1)?puts("si\n"):puts("no\n");
	//EsVaciaG(lg1)?puts("si\n"):puts("no\n");
	EsAtomo(lg4)?puts("Si\n"):puts("No\n");
	
	ImpElem(CabezaElem(CabezaLista(lg1)));
	//printf("%d\n",NumElemListaGen(lg2));
	//printf("%d\n",NumElemListaGen(lg3));
	//printf("%d\n",NumElemListaGen(lg4));
	//printf("%d\n",NumElemListaGen(lg1));

	//puts("Los elementos de la lista lg1 son: \n");
	//printf("[");
//	ImpListaGen(lg1);
	//printf("]");
	return 0;
}
