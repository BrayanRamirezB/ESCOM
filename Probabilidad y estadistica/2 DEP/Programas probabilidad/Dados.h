int dado(){
	int d1, d2, sumad1d2;
	
	d1 = 1 + (rand() % 6);
	d2 = 1 + (rand() % 6);
	sumad1d2 = d1 + d2;
	printf("Has obtenido %d + %d = %d\n\n\n", d1, d2, sumad1d2);
		
	return sumad1d2;
}

int Victoria(int i){ return i == 7||i == 11;}

int Derrota(int i){ return i == 2||i == 3||i == 12;}

int EsPunto(int i, int j){ return i == j;}

void tabla(int t[], int n){

	printf("---------- Tabla ----------\n\n");
	printf("Probabilidad   Resultado   Frecuencia   Frecuencia Relativa  \n");
	printf("0.0277");printf("         2           ");printf("%d", t[0]);printf("            %f\n", (float)t[0]/(float)n);
	printf("0.0555");printf("         3           ");printf("%d", t[1]);printf("            %f\n", (float)t[1]/(float)n);
	printf("0.0833");printf("         4           ");printf("%d", t[2]);printf("            %f\n", (float)t[2]/(float)n);
	printf("0.0111");printf("         5           ");printf("%d", t[3]);printf("            %f\n", (float)t[3]/(float)n);
	printf("0.1388");printf("         6           ");printf("%d", t[4]);printf("            %f\n", (float)t[4]/(float)n);
	printf("0.1666");printf("         7           ");printf("%d", t[5]);printf("            %f\n", (float)t[5]/(float)n);
	printf("0.1388");printf("         8           ");printf("%d", t[6]);printf("            %f\n", (float)t[6]/(float)n);
	printf("0.0111");printf("         9           ");printf("%d", t[7]);printf("            %f\n", (float)t[7]/(float)n);
	printf("0.0833");printf("         10          ");printf("%d", t[8]);printf("            %f\n", (float)t[8]/(float)n);
	printf("0.0555");printf("         11          ");printf("%d", t[9]);printf("            %f\n", (float)t[9]/(float)n);
	printf("0.0277");printf("         12          ");printf("%d", t[10]);printf("            %f\n", (float)t[10]/(float)n);
	printf("        Total : %d", n);
	puts("");
}

int AsignaTabla(int t[], int sdados){

	if(sdados == 2){
		t[0] = t[0] + 1;
		return *t;
	}else if(sdados == 3){
		t[1] = t[1] + 1;
		return *t;
	}else if(sdados == 4){
		t[2] = t[2] + 1;
		return *t;
	}else if(sdados == 5){
		t[3] = t[3] + 1;
		return *t;
	}else if(sdados == 6){
		t[4] = t[4] + 1;
		return *t;
	}else if(sdados == 7){
		t[5] = t[5] + 1;
		return *t;
	}else if(sdados == 8){
		t[6] = t[6] + 1;
		return *t;
	}else if(sdados == 9){
		t[7] = t[7] + 1;
		return *t;
	}else if(sdados == 10){
		t[8] = t[8] + 1;
		return *t;
	}else if(sdados == 11){
		t[9] = t[9] + 1;
		return *t;
	}else if(sdados == 12){
		t[10] = t[10] + 1;
		return *t;
	}	
}

void Punto(int sdados){
	int contador = 1, opc, sdados2;
	
	while(contador == 1){
		printf("1) Lanzar otra vez los dados.\n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				printf("%d Es el punto.\n\n",sdados);
				sdados2 = dado();
				if(EsPunto(sdados, sdados2)){
					printf("Usted gana!!!\n\n");
					contador = 0;
				}else if(sdados2 == 7){
					printf("La casa gana!!!\n\n");
					contador = 0;
				}else
					printf("No es el punto.\n\n");
			break;
			default:
				system("cls");
				printf("Opcion no disponible.\n\n");
			break;	
		}	
	}
}

void QP(int sdados){
	
	if(Victoria(sdados))
		printf("Usted gana!!!\n\n");
	else if(Derrota(sdados))
		printf("La casa gana!!!\n\n");	
	else{
		Punto(sdados);
	}
}

int Punto3(int Apuesta, int sdados, int saldoBanco){
	int contador = 1, opc, sdados2;
	
	while(contador == 1){
		printf("1) Lanzar otra vez los dados.\n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				printf("%d Es el punto.\n\n",sdados);
				sdados2 = dado();
				if(EsPunto(sdados, sdados2)){
					printf("Usted gana %d !!!\n\n", 2*Apuesta);
					saldoBanco = saldoBanco + Apuesta;
					contador = 0;
					return saldoBanco;
				}else if(sdados2 == 7){
					printf("La casa gana %d !!!\n\n", Apuesta);
					saldoBanco = saldoBanco - Apuesta;
					contador = 0;
					return saldoBanco;
				}else
					printf("No es el punto.\n\n");
			break;
			default:
				system("cls");
				printf("Opcion no disponible.\n\n");
			break;	
		}	
	}
}

int QP3(int Apuesta, int sdados, int saldoBanco){
	
	if(Victoria(sdados)){
		printf("Usted gana %d!!!\n\n", 2*Apuesta);
		saldoBanco = saldoBanco + Apuesta;
		return 	saldoBanco;
	}
	else if(Derrota(sdados)){
		printf("La casa gana %d!!!\n\n", Apuesta);
		saldoBanco = saldoBanco - Apuesta;
		return 	saldoBanco;
	}
	else{
		saldoBanco = Punto3(Apuesta, sdados, saldoBanco);
		return saldoBanco;
	}
}

int dado2(){
	int d1, d2, sumad1d2;
	
	d1 = 1 + (rand() % 6);
	d2 = 1 + (rand() % 6);
	sumad1d2 = d1 + d2;
		
	return sumad1d2;
}















