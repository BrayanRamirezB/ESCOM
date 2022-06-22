typedef Lista *TablaH;

TablaH consH(int n){
    TablaH t=(TablaH)malloc(sizeof(Lista)*n);
    return t;
}

TablaH insertaH(int llave, Elem e, TablaH t){ 
	int ind=indice(llave,num);
	
	t[ind]=cons(e,t[ind]);
	return t;	
}

int estaenH(int llave, TablaH t){
	int ind=indice(llave,num);
	
	if(esvacia(t[ind]))
		return 0;	
	else{
		if(Deterllave(cabeza(t[ind]))==llave)
			return 1;
		else
			return EstaenL(llave,t[ind]);
	}
}

Elem consulta(int llave, TablaH t){
	int ind=indice(llave,num);
	
	if(estaenH(llave,t)){
		if(Deterllave(cabeza(t[ind]))==llave)
			return cabeza(t[ind]);
		else
			return copElem(llave,t[ind]);
	}else
		return VacioElem();
}

TablaH elimina(int llave, TablaH t){
	int ind=indice(llave,num);
	
	if(estaenH(llave,t)){
		if(Deterllave(cabeza(t[ind]))==llave){
			t[ind]=resto(t[ind]);
			return t;
		}else{
			t[ind]=borraElem(llave,t[ind]);
			return t;
		}	
	}else
		return t;
}





