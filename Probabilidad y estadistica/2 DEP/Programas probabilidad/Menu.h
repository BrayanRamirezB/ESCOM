void PR1(){
	int opc, contador = 1, sdados,total = 0, t[11] = {0,0,0,0,0,0,0,0,0,0,0};
	
	while(contador == 1){
		printf("------------------ Programa 1 ------------------\n\n");
		printf("1) Lanzar los dos dados.\n\n2) Salir.\n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				sdados = dado();
				total = total + 1;
				t[11] = AsignaTabla(t, sdados);
				tabla(t, total);
			break;
			case 2:
				contador = 0;
				system("cls");
				printf("bis gleich!!!!\n");
			break;
			default:
				system("cls");
				printf("Opcion no disponible.\n\n");
			break;
		}	
	}		
}

void PR2(){
	int opc, contador = 1, sdados;
	
	while(contador == 1){
		printf("------------------ Programa 2 ------------------\n\n");
		printf("------------------    CRAPS   ------------------\n\n");
		printf("1) Lanzar los dados.\n\n2) Salir.\n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				sdados = dado();
				QP(sdados);
			break;
			case 2:
				contador = 0;
				system("cls");
				printf("bis gleich!!!!\n");
			break;
			default:
				system("cls");
				printf("Opcion no disponible.\n\n");
			break;	
		}
	}
}

int PR3(int Apuesta, int saldoBanco){
	int sdados;

	system("cls");
	sdados = dado();
	saldoBanco = QP3(Apuesta, sdados, saldoBanco);
	
	return saldoBanco;
}

void PR4(){
	int i = 0,cont,opc, contador = 1, sdados,total = 0, t[11] = {0,0,0,0,0,0,0,0,0,0,0};
	
	while(contador == 1){
		printf("------------------ Programa 1 ------------------\n\n");
		printf("1) Lanzar los dados.\n\n2) Salir.\n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				printf("Cuantos lanzamientos?\n\n");
				scanf("%d",&cont);
				puts("");
				while(i<cont){
					sdados = dado2();
					total = total + 1;
					t[11] = AsignaTabla(t, sdados);
					i++;
				}
				tabla(t, total);
			break;
			case 2:
				contador = 0;
				system("cls");
				printf("bis gleich!!!!\n");
			break;
			default:
				system("cls");
				printf("Opcion no disponible.\n\n");
			break;
		}	
	}		
}



















