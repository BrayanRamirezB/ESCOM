typedef char Vertice;

typedef char Arista;

typedef Vertice Elem;

typedef struct {

	Arista N;
	Vertice y;

}ElemArista;

void ImpElem(Elem e){ printf("%c",e);}

void ImpElemArista(ElemArista e){ printf(" (Arista: %c , Vertice: %c) ,",e.N,e.y); }

void ImpHamilt(ElemArista e){ printf(" (Vertice x: %c , Vertice y: %c) ,",e.N,e.y); }

Arista EscribeElemArista(ElemArista e){
	printf("Ingresa el caracter de la arista :\n");
	scanf(" %c",&e.N);
	
	return e.N;
}

int VerticesIguales(Vertice x, Vertice y){ return strcmp(x,y);}

int EsIgualElem(Elem e1,Elem e2){ return e1==e2;}

int EsIgualArista(ElemArista e1, ElemArista e2){ return e1.N==e2.N&&e1.y==e2.y; }

int EsImpar(int i){
	int a=i%2;
	
	if(a==0)
		return 1;
	else
		return 0;	
}
