
void leearreglo(FILE *ENT,char* a[],int tam){//recoge la tabla de trancisiones del documento de texto
	int i;
	  
	for(i=0;i<tam;i++) 
		LeeElem(ENT,a[i]=(Elem)malloc(80));
}

void escribearreglo(Elem a[],int tam){// muestra en pantalla la tabla de transiciones
	int i;
	
	for(i=0;i<tam;i++)
	    ImpElem(a[i]);	
}

int tamarreglo(FILE *ENT, Elem a[]){// devuelve la cantidad de cadenas de un documento de texto
	int i;
	
	for(i=0;(fscanf(ENT,"%s",a))!=EOF;i++){
	}//tamaño del arreglo
	return i;
}

//escribearreglo(ttransicion,i); //esta funcion permite imprimir en pantalla el automata en una sola columna






















