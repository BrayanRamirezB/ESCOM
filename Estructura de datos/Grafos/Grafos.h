typedef ListaGen Grafo;

Grafo NuevoG(){ return NULL;}

Grafo AgregaVertice(Grafo g, Vertice x){ return ConsG(x,g); }

int ContieneVertice(Grafo g, Vertice x){return EstaEnG(x,g);}

int Adyacente(Grafo g, Vertice x, Vertice y){
	if(ContieneVertice(g,x)&&ContieneVertice(g,y)){
		return EstaArista(x,y,g)||EstaArista(y,x,g);
	}else
		return 0;	
}

Lista Vecinos(Grafo g, Vertice x){
	if(!EsVaciaG(g)){
		if(EsIgualElem(CabezaG(g),x))
			return ListaG(g);
		else
			return Vecinos(RestoG(g),x);
	}
}

ElemArista IniciaValorArista(Grafo g, Vertice y){
	ElemArista e;

	e.N=EscribeElemArista(e);
	e.y=y;

	return e;
}

ElemArista ObtenValorArista(Grafo g, Vertice x, Vertice y){
	if(!EsVaciaG(g)){
		if(EsIgualElem(CabezaG(g),x))
			return ConsultaL(y,ListaG(g));
		else
			return ObtenValorArista(RestoG(g),x,y);
	}
}

Grafo AgregaArista(Grafo g, Vertice x,Vertice y){
	ElemArista e;

	e = IniciaValorArista(g,y);

	return LlenaLista(x,e,g);
}

Grafo EliminaArista(Grafo g,Vertice x, Vertice y){
	ElemArista e;

	e = ObtenValorArista(g,x,y);

	return EliminaLista(x,e,g);
}

ElemVertice ObtenValorVertice(Grafo g, Vertice x){
	if(!EsVaciaG(g)){
		if(EsIgualElem(CabezaG(g),x))
			return HazElemVertice(CabezaG(g),ListaG(g));
		else
			return ObtenValorVertice(RestoG(g),x);		
	}
}

Grafo EliminaVertice(Grafo g, Vertice x){
	if(EsVaciaG(g))
		return g;
	else{
		g = EliminaG(x,g);
		g = EliminaAristaVertice(x,g);
		return g;
	}
}

Lista DeteH(Grafo g, Lista l, ElemArista e){
	ElemArista v;

	if(EsVaciaG(g)||EsVaciaL(ListaG(g)))
		return l;
	else{
		v = CabezaL(Vecinos(g,e.y));
		v.N=e.y;
		l = ConsL(v,l);
		g = EliminaVertice(g,v.N);
		return DeteH(g,l,v);
	}
}

Lista ListaHamiltoniana(Grafo g){
	Lista l=VaciaL();
	ElemArista e;
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));

	temp = g;
	
	if(!EsVaciaG(temp)){
		e = CabezaL(ListaG(temp));
		e.N = CabezaG(temp);
		l = ConsL(e,l);
		temp = EliminaVertice(temp,CabezaG(temp));
		return DeteH(temp,l,e);	
	}
}

int EsEuleriano(Grafo g,int i){	
	if(EsVaciaG(g)){
		if(i==2||i==0)
			return 1;
		else
			return 0;	
	}else{
		if(EsImpar(NumElemList(ListaG(g))))
			return EsEuleriano(RestoG(g),i++);
		else
			return EsEuleriano(RestoG(g),i);	
	}	
}

Lista DeteE(Grafo g, Lista l, ElemArista e){
	ElemArista v;

	if(EsVaciaG(g)||EsVaciaL(ListaG(g)))
		return l;
	else{
		v = CabezaL(Vecinos(g,e.y));
		v.N=e.y;
		l = ConsL(v,l);
		g = EliminaArista(g,v.N,v.y);
		g = EliminaArista(g,v.y,v.N);
		return DeteE(g,l,v);
	}
}

Lista ListaEuleriana(Grafo g){
	Lista l=VaciaL();
	ElemArista e;
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));

	temp = g;
	
	if(EsEuleriano(temp,0)){
		e = CabezaL(ListaG(temp));
		e.N = CabezaG(temp);
		l = ConsL(e,l);
		temp = EliminaArista(temp,CabezaG(temp),e.y);
		temp = EliminaArista(temp,e.y,CabezaG(temp));
		return DeteE(temp,l,e);	
	}
}

