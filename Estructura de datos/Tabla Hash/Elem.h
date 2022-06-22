#define num 53

typedef struct {
	char Nombre[20];
	char simbolo[5];
	int Natom;
}Elem;

Elem LeeElem(Elem e){
	printf("Ingrese el Nombre\n"); 
	scanf("%s",&e.Nombre);
	printf("Ingrese el simbolo\n"); 
	scanf("%s",&e.simbolo);
	printf("Ingrese el Numero atomico\n"); 
	scanf("%d",&e.Natom);			
	return e;
}

void ImpElem(Elem e){ printf("Nombre: %s\nSimbolo: %s\nNumero atomico: %d\n",e.Nombre,e.simbolo,e.Natom); }

int Tamcadena(Elem e){
	int largo=0;
	
	while (e.Nombre[largo]!='\0') largo++;
	return largo;
}

int indice(int llave,int n){ return llave%n; }

int Deterllave(Elem e){
	int i,t=0,n=Tamcadena(e);
	
	for(i=0;i<n;i++)
		t=t+e.Nombre[i];
	
	return t;
}

Elem VacioElem(){
	Elem e;
	
	strcpy(e.Nombre,"");
	strcpy(e.simbolo,"");
	e.Natom=0;
	return e;
}



