typedef char* Elem;

void ImpElem(Elem e){ fprintf(stdout,"%s\n",e);	}//imprime en pantalla un elemento

void LeeElem(FILE *ENT,Elem e){	fscanf(ENT,"%s",e);	}// recoge una cadena de un documento de texto




