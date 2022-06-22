typedef struct{
	
	Vertice x;
	Lista l;

}ElemVertice;

ElemVertice HazElemVertice(Elem e, Lista l){
	ElemVertice v;

	v.l=l;
	v.x=e;

	return v;
}

void ImpElemVertice(ElemVertice e){
	ImpElem(e.x);
	printf("[ ");
	ImpListaL(e.l);
	printf("],");
}



/*
Lista k=VaciaL(),l=VaciaL();
	ListaGen lg=VaciaG();
	ElemArista e,f,g,h;
	char u='a',v='b',w='c',x='d',z='e';
	
	e.N='2';
	e.y = w;
	f.N='3';
	f.y=z;
	g.N='4';
	g.y = w;
	h.N='5';
	h.y=x;
	
	lg=ConsG(u,ConsG(v,ConsG(w,ConsG(x,lg))));
	ImpGen(lg);
	puts("");
				
	lg=LlenaLista(v,e,lg);
	
	lg=LlenaLista(u,h,lg);
	
	ImpComp(lg);
	
	puts("");
	
	lg=EliminaLista(v,e,lg);
	
	ImpComp(lg);	
	g = AgregaVertice(g,'a');
	ImpComp(g);
	
	g=EliminaVertice(g,'f');
	
	printf("%d",ContieneVertice(g,'a'));
	puts("");
	printf("%d",Adyacente(g,'d','c'));
	puts("");
	
	g = AgregaArista(g,'a','c');
	puts("");
	g = AgregaArista(g,'a','b');
	puts("");
	g = AgregaArista(g,'b','a');
	puts("");
	g = AgregaArista(g,'b','c');
	puts("");
	g = AgregaArista(g,'c','a');
	puts("");
	g = AgregaArista(g,'c','b');
	puts("");
	g = AgregaArista(g,'d','a');
	puts("");
	g = AgregaArista(g,'a','d');
	puts("\n");
	
	g = EliminaArista(g,'a','b');
	puts("");
	
	g=EliminaVertice(g,'a');
	ImpComp(g);
	ImpListaL(Vecinos(g,'d'));
	ImpElemArista(ObtenValorArista(g,'a','c'));
	ImpComp(g);

*/


