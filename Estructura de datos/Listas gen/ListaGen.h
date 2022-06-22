typedef struct NodoListaGen{
	int EsAtomo;
	union {
		Elem Atomo;
	struct NodoListaGen *ListaGenElem ;
	} dato;
		struct NodoListaGen *sig;
	}*ListaGen;


ListaGen VaciaG(){return NULL;}

ListaGen ConsElem(Elem e, ListaGen lg){
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
	temp->EsAtomo = 1;
	temp->dato.Atomo = e;
	temp->sig = lg;
	return temp;
}


ListaGen ConsLista(ListaGen e, ListaGen lg){
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
	temp->EsAtomo = 0;
	temp->dato.ListaGenElem = e;
	temp->sig = lg;
	return temp;
}

int EsVaciaG(ListaGen lg){ return lg==NULL;}

Elem CabezaElem(ListaGen lg){ return lg->dato.Atomo;}

ListaGen CabezaLista(ListaGen lg){ return lg->dato.ListaGenElem;}

ListaGen RestoG(ListaGen lg){ return lg->sig;}

int EsAtomo(ListaGen lg){ return lg->EsAtomo;}

int NumElemListaGen(ListaGen lg){
	if(EsVaciaG(lg))
		return 0;
	else
		return 1+NumElemListaGen(RestoG(lg));	
}

void ImpListaGen(ListaGen lg){
	if(!EsVaciaG(lg)){
		if(EsAtomo(lg)){
			ImpElem(CabezaElem(lg));
			ImpListaGen(RestoG(lg));
		}else{
			printf("[");
			ImpListaGen(CabezaLista(lg));
			printf("],");
			ImpListaGen(RestoG(lg));
		}		
	}
}

ListaGen EliminaElem(Elem e, ListaGen lg){
	if(EsVaciaG(lg))
		return lg;
	else{
		if(EsAtomo(lg)){
			if(CabezaElem(lg)==e)
				return RestoG(lg);
			else
				return EliminaElem(e,RestoG(lg));	
		}else{
			
		}
	}	
}
