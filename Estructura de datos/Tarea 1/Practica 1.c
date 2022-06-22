#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "Lista.h"

int main(){
	
	Lista l=Cons(3,Cons(1,Cons(6,Cons(4,Cons(8,Cons(9,Cons(7,Cons(2,Cons(0,Vacia())))))))));
	Lista l1=Cons(11,Cons(16,Cons(12,Cons(24,Cons(10,Cons(1,Cons(5,Cons(4,Cons(8,Cons(0,Vacia()))))))))));
	
		
	ImpLista(OrdListMezcla(l));	
	return 0;
}



/*
Nombre: Brayan Ramirez Benitez
Grupo: 1CM7

-------------------Soy un comentario--------------------------

Si desea saber cual es la mitad inferior de la lista "l"

ImpLista(MitadInfe(l));

Si desea saber cual es la mitad superior de la lista "l"

ImpLista(MitadSupe(l));

*/
