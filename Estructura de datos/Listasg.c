/*
ListaGen lg2=[[1,2,3,[4,5,[6,7,8],9],10],20,30,[40,50,60],100,200];

ListaGen la0 = consg(40,consg(50,consg(60,vaciag())));
ListaGen la1 = consg(6,consg(7,consg(8,vacia())));
ListaGen la2 = consg(4,consg(5,conslista(la1,consg(9,vaciag()))));
ListaGen la3 = consg(1,consg(2,consg(3,conslista(la2,consg(10,vaciag())))));


ListaGen la = conslista(la3,consg(20,consg(30,conslista(la0,consg(100,consg(200,vaciag()))))));

*/

int NumElemG(ListaGen lg){
	if(EsVacia(lg))
		return 0;
	else if(EsLista(lg))
	//Dado que lg tiene como cabeza una ListaGen se deberá llamar recursivamente a si misma para contar los elementos tanto de la "Cabeza" como del "Resto"
		return NumElemG(CabezaG(lg))+NumElemG(RestoG(lg));	
	else
	//Como la lista no es Vacia ademas su "Cabeza" no es una ListaGen, entonces tendrá por lo menos un elemento, sin embargo el "Resto" puede tener más elementos
		return 1+NumElemG(RestoG(lg));
}

void ImplistaGen(ListaGen lg){
	if(!EsVacia(lg)){
		//Si lg tiene como "Cabeza" una ListaGen, si no esta tendrá un elemento de tipo "Elem" 
		if(EsLista(lg)){
			//Dado que lg tiene como cabeza una ListaGen se deberá llamar recursivamente a si misma para imprimir los elementos tanto de la "Cabeza" como del "Resto"
			ImpListaGen(CabezaG(lg));
			ImpListaGen(RestoG(lg));
		}else{
			//Sea ImpElem una función trivial, que imprime el tipo de dato definido como "Elem" y se llamará recursivamente para imprimir los elementos del "Resto"
			ImpElem(CabezaG(lg));
			ImpListaGen(RestoG(lg));
		}
	}else
		puts("");
}

