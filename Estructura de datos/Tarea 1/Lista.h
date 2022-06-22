typedef struct Nodo{

	Elem dato;
	struct Nodo *Sig;

} *Lista;

Lista Vacia(){ return NULL; }

Lista Cons(Elem e, Lista l){
	
	Lista t=(Lista)malloc(sizeof(struct Nodo));
	
	t->dato=e;
	t->Sig=l;
	
	return t;
}

int EsVacia(Lista l){ return l==NULL; }

Elem Cabeza(Lista l){ return l->dato; }

Lista Resto(Lista l){ return l->Sig; }

void ImpLista(Lista l){
	
	if(!EsVacia(l)){	
		ImpElem(Cabeza(l));
		ImpLista(Resto(l));
	}
}

int NumElemList(Lista l){
	
	if(EsVacia(l))
		return 0;
	else
		return 1+NumElemList(Resto(l));	
}

Lista PegaList(Lista l1,Lista l2){
	if(EsVacia(l1))
		return l2;
	else if(EsVacia(l2))
		return l1;
	else
		return Cons(Cabeza(l1),PegaList(Resto(l1),l2));	
} 

Lista InvList(Lista l){
	if(EsVacia(l))
		return l;
	else
		return PegaList(InvList(Resto(l)),Cons(Cabeza(l),Vacia()));
}

Lista InsOrd(Elem e,Lista l){
	if(EsVacia(l))
		return Cons(e,l);
	else if(EsMenor(e,Cabeza(l)))
		return Cons(e,l);
	else
		return Cons(Cabeza(l),InsOrd(e,Resto(l)));	 
}

Lista OrdList(Lista l){
	if(EsVacia(l))
		return l;
	else
		return InsOrd(Cabeza(l),OrdList(Resto(l)));	
}

int EstElem(Elem e,Lista l){
	if(EsVacia(l))
		return 0; 
	else if(EsIgual(e,Cabeza(l)))
		return 1;
	else
		return EstElem(e,Resto(l));	
}

int IguList(Lista l1,Lista l2){
	if(EsVacia(l1)&&EsVacia(l2))
		return 1;
	else if(EsVacia(l1)&&!EsVacia(l2)||!EsVacia(l1)&&EsVacia(l2))
		return 0;	
	else if(EsIgual(Cabeza(l1),Cabeza(l2)))
		return IguList(Resto(l1),Resto(l2));
}

int PalinList(Lista l1){ return IguList(l1,InvList(l1)); }

Lista MitadInfe(Lista l){
	int i,c = NumElemList(l)/2;
	
	l=InvList(l);
	for(i=0;i<c;i++)
		l=Resto(l);
	l=InvList(l);	
	return l;	
}

Lista MitadSupe(Lista l){
	int i,c = NumElemList(l)-(NumElemList(l)/2);
	
	for(i=0;i<c;i++)
		l=Resto(l);
	l=InvList(l);	
	return l;
}

Lista Mezclar(Lista l1,Lista l2){
	Elem c1,c2;
	Lista lo=Vacia();
	
	if(EsMenor(Cabeza(InvList(l1)),Cabeza(l2)))
		return PegaList(l1,l2);
	else if(EsMenor(Cabeza(InvList(l2)),Cabeza(l1)))
		return PegaList(l2,l1);	
	else{
		while(!EsVacia(l1)&&!EsVacia(l2)){
		c1=Cabeza(l1);
		c2=Cabeza(l2);
		
		if(EsMenor(c1,c2)){
			lo=Cons(c1,lo);
			l1=Resto(l1);
		}else{
			lo=Cons(c2,lo);
			l2=Resto(l2);
			}
		}
		lo=InvList(lo);
		if(EsVacia(l1))
			PegaList(lo,l2);
		else
			PegaList(lo,l1);
		return lo;
	}	
}

Lista OrdListMezcla(Lista l){
	Lista lo;
	
	if(EsVacia(l))
		return l;
	else
		return Mezclar(OrdList(MitadInfe(l)),OrdList(MitadSupe(l)));
}


