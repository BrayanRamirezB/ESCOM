Elem ingresac(Elem e, char c, Elem a[]){//Devuelve un estado asignado para un caracter respecto a la tabla de transiciones
	
	if(e[2] == '0'){
		if(c == '0')
			return a[1];
		else if(c == '1')
			return a[2];
	}else if(e[2] == '1'){
		if (c == '0')
			return a[4];
		else if(c == '1')
			return a[5];
	}else if(e[2] == '2'){
		if (c == '0')
			return a[7];
		else if(c == '1')
			return a[8];
	}else if(e[2] == '3'){
		if (c == '0')
			return a[10];
		else if(c == '1')
			return a[11];	
	}else if(e[2] == '4'){
		if (c == '0')
			return a[13];
		else if(c == '1')
			return a[14];	
	}else if(e[2] == '5'){
		if (c == '0')
			return a[16];
		else if(c == '1')
			return a[17];	
	}else
		return "-0-";
}

Elem compruebac (Elem a[], Elem cadena){//Comprobacion para cada caracter de la cadena ingresada, regresa el ultimo estado al que se llego
	int i, j = 0, tam;
	Elem estado = a[0];//recoge el estado inicial del automata
	
	tam = strlen(cadena);//cantidad de caracteres de una cadena
	i = tam-1;
	
	while(j<=i){//envia a la funcion ingresac un estado, un caracter de la cadena y la tabla de trancision del automata donde regresa un estado
		estado = ingresac(estado, cadena[j], a);
		j++;
	}
	
	return estado;
}

void EsEstadodeAcep(Elem estador){//comprueba si el ultimo estado es de aceptacion	
	
	if (estador[0] == '*')// si el estado contiene un * quiere decir que es de aceptacion
		printf("\nLa cadena fue aceptada por el automata\n");
	else// en caso contrario es un estado inicial, normal o vacio
		printf("\nLa cadena fue rechazada por el automata\n");
	
}









