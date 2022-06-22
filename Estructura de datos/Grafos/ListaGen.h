typedef struct Nodo{
	
	ElemArista dt;
	struct Nodo *sig;

}*Lista;

typedef struct NodoListaGen{

	Elem dato;
	Lista l;
	struct NodoListaGen *sig;

}*ListaGen;

//funciones para Lista de vertices

ListaGen VaciaG(){return NULL;}

int EsVaciaG(ListaGen lg){ return lg==NULL;}

ListaGen ConsG(Elem e, ListaGen lg){
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
	
	temp->dato = e;
	temp->l = NULL;
	temp->sig = lg;	
	
	return temp;
}

ListaGen EditG(Elem e, Lista li, ListaGen lg){
	ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
	
	temp->dato = e;
	temp->l = li;
	temp->sig = lg;	
	
	return temp;
}

Elem CabezaG(ListaGen lg){ return lg->dato;}

ListaGen RestoG(ListaGen lg){ return lg->sig;}

Lista ListaG(ListaGen lg){ return lg->l; }

ListaGen EliminaG(Elem e, ListaGen lg){
	if(EsVaciaG(lg))
		return lg;
	else{
		if(EsIgualElem(e,CabezaG(lg)))
			return RestoG(lg);
		else
			return EditG(CabezaG(lg),ListaG(lg),EliminaG(e,RestoG(lg)));	
	}	
}

void ImpGen(ListaGen lg){
	if(!EsVaciaG(lg)){
			ImpElem(CabezaG(lg));
			ImpGen(RestoG(lg));
	}
}

int EstaEnG(Elem e,ListaGen lg){
	if(EsVaciaG(lg))
		return 0;
	else{
		if(EsIgualElem(CabezaG(lg),e))
			return 1;
		else
			return EstaEnG(e,RestoG(lg));	
	}	
}

//Funciones para Lista de aristas

Lista VaciaL(){ return NULL;}

int EsVaciaL(Lista l){ return l==NULL;}

Lista ConsL(ElemArista e, Lista l){
	Lista t=(Lista)malloc(sizeof(struct Nodo));
	
	t->dt=e;
	t->sig=l;
	
	return t;
}

ElemArista CabezaL(Lista l){ return l->dt; }

Lista RestoL(Lista l){ return l->sig; }

Lista EliminaL(ElemArista e, Lista l){
	if(EsVaciaL(l))
		return l;
	else{
		if(EsIgualArista(e,CabezaL(l)))
			return RestoL(l);
		else
			return ConsL(CabezaL(l),EliminaL(e,RestoL(l)));	
	}	
}

ElemArista ConsultaL(Elem e, Lista l){
	if(!EsVaciaL(l)){
		if(EsIgualElem(CabezaL(l).y,e)){
			return CabezaL(l);
		}else
			return ConsultaL(e,RestoL(l));
	}
}

int EstaEnL(Elem e,Lista l){
	if(EsVaciaL(l))
		return 0;
	else{
		if(EsIgualElem(CabezaL(l).y,e)){
			return 1;
		}else
			return EstaEnL(e,RestoL(l));
	}
}

int NumElemList(Lista l){
	if(EsVaciaL(l))
		return 0;
	else
		return 1+NumElemList(RestoL(l));	
}

void ImpListaL(Lista l){	
	if(!EsVaciaL(l)){	
		ImpElemArista(CabezaL(l));
		ImpListaL(RestoL(l));
	}
}

void ImpListHamilt(Lista l){
	if(!EsVaciaL(l)){	
		ImpHamilt(CabezaL(l));
		ImpListHamilt(RestoL(l));
	}
}

//-----------------------------------------------------Aqui empieza lo bueno------------------------------------------------------ 

void ImpComp(ListaGen lg){
	if(!EsVaciaG(lg)){
		ImpElem(CabezaG(lg));
		if(!EsVaciaL(ListaG(lg))){
			printf("[");
			ImpListaL(ListaG(lg));
			printf("], ");
		}
		ImpComp(RestoG(lg));	
	}
}

ListaGen LlenaLista(Elem e, ElemArista v, ListaGen lg){
	if(EsVaciaG(lg))
		return lg;
	else{
		if(EsIgualElem(CabezaG(lg),e)){
			lg = EditG(e,ConsL(v,ListaG(lg)),RestoG(lg));
			return lg;
		}else
			return EditG(CabezaG(lg),ListaG(lg),LlenaLista(e,v,RestoG(lg)));
	}	
}

ListaGen EliminaLista(Elem e, ElemArista v, ListaGen lg){
	if(EsVaciaG(lg))
		return lg;
	else{
		if(EsIgualElem(CabezaG(lg),e)){
			lg = EditG(e,EliminaL(v,ListaG(lg)),RestoG(lg));
			return lg;
		}else
			return EditG(CabezaG(lg),ListaG(lg),EliminaLista(e,v,RestoG(lg)));
	}
}

ListaGen EliminaAristaVertice(Elem e, ListaGen lg){
	if(EsVaciaG(lg))
		return lg;
	else{
		if(EstaEnL(e,ListaG(lg))){
			lg = EliminaLista(CabezaG(lg),ConsultaL(e,ListaG(lg)),lg);
			return EditG(CabezaG(lg),ListaG(lg),EliminaAristaVertice(e,RestoG(lg)));
		}else
			return EditG(CabezaG(lg),ListaG(lg),EliminaAristaVertice(e,RestoG(lg)));
	}
}

int EstaArista(Elem e1, Elem e2, ListaGen g){
	if(EsVaciaG(g))
		return 0;
	else{
		if(EsIgualElem(CabezaG(g),e1))
			return EstaEnL(e2,ListaG(g));
		else
			return EstaArista(e1,e2,RestoG(g));
	}	
}

