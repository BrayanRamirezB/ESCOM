#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "ListaGen.h"
#include "ElemVertice.h"
#include "Grafos.h"

int main(){
	Grafo f=NuevoG(),g=NuevoG();
	Lista l,k;
	g = AgregaVertice(AgregaVertice(AgregaVertice(AgregaVertice(AgregaVertice(g,'e'),'d'),'c'),'b'),'a');
	//f = AgregaVertice(AgregaVertice(AgregaVertice(f,'c'),'b'),'a'); 
	
	g = AgregaArista(g,'a','e');
	puts("");
	g = AgregaArista(g,'a','b');
	puts("");
	g = AgregaArista(g,'b','d');
	puts("");
	g = AgregaArista(g,'b','c');
	puts("");
	g = AgregaArista(g,'b','a');
	puts("");
	g = AgregaArista(g,'c','d');
	puts("");
	g = AgregaArista(g,'c','b');
	puts("");
	g = AgregaArista(g,'d','e');
	puts("");
	g = AgregaArista(g,'d','c');
	puts("");
	g = AgregaArista(g,'d','b');
	puts("");
	g = AgregaArista(g,'e','a');
	puts("");
	g = AgregaArista(g,'e','d');
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
	l = ListaHamiltoniana(g);
	//k = ListaHamiltoniana(f);
	printf("Lista Hamiltoniana\n");
	ImpListHamilt(l);
	//ImpListHamilt(k);
	puts("\n\n");
	//printf("%d",EsEuleriano(f,0));
	//ImpComp(f);
	return 0;
}


