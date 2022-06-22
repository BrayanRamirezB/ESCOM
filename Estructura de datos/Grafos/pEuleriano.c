#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "ListaGen.h"
#include "ElemVertice.h"
#include "Grafos.h"

int main(){
	Grafo g=NuevoG();
	Lista l=VaciaL();
	g = AgregaVertice(AgregaVertice(AgregaVertice(AgregaVertice(AgregaVertice(g,'e'),'d'),'c'),'b'),'a');
	//f = AgregaVertice(AgregaVertice(AgregaVertice(f,'c'),'b'),'a'); 
	
	g = AgregaArista(g,'a','e');
	puts("");
	g = AgregaArista(g,'a','d');
	puts("");
	g = AgregaArista(g,'a','b');
	puts("");
	g = AgregaArista(g,'b','d');
	puts("");
	g = AgregaArista(g,'b','e');
	puts("");
	g = AgregaArista(g,'b','c');
	puts("");
	g = AgregaArista(g,'b','a');
	puts("");
	g = AgregaArista(g,'c','d');
	puts("");
	g = AgregaArista(g,'c','b');
	puts("");
	g = AgregaArista(g,'d','a');
	puts("");
	g = AgregaArista(g,'d','b');
	puts("");
	g = AgregaArista(g,'d','c');
	puts("");
	g = AgregaArista(g,'d','e');
	puts("");
	g = AgregaArista(g,'e','a');
	puts("");
	g = AgregaArista(g,'e','d');
	puts("");
	g = AgregaArista(g,'e','b');
	puts("");
	/*
	f = AgregaArista(f,'a','c');
	puts("");
	f = AgregaArista(f,'a','b');
	puts("");
	f = AgregaArista(f,'b','c');
	puts("");
	f = AgregaArista(f,'b','a');
	puts("");
	f = AgregaArista(f,'c','a');
	puts("");
	f = AgregaArista(f,'c','b');
	puts("");
	ImpComp(f);
	*/
	puts("");
	l = ListaEuleriana(g);
	printf("Lista Euleriana\n");
	ImpListHamilt(l);
	puts("\n\n");
	//printf("%d",EsEuleriano(f,0));
	ImpComp(g);
	return 0;
}


