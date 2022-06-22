#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include"Dados.h"
#include"Menu.h"



int main(){
	int Ap, opc, ad = 1, saldoBanco = 1000;
	srand(time(NULL));
	
	printf("------------------ Programa  ------------------\n\n");
	printf("-------------- CRAPS CON APUESTAS --------------\n\n\n");
	
	while(saldoBanco>0&&ad == 1){
		printf("Tu saldo es %d\n\n\n", saldoBanco);
		printf("1) Apostar.\n\n2) Salir.\n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				printf("\nIngrese la apuesta.\n\n");
				scanf("%d",&Ap);
				if(Ap<=saldoBanco&&Ap>0){
					saldoBanco = PR3(Ap, saldoBanco);
				}else{
					system("cls");
					printf("\nNo puedes permitirte esta apuesta, te regresare al menu.\n\n");
				}
			break;
			case 2:
				system("cls");
				ad = 0;
			break;
			default:
				system("cls");
				printf("Opcion no valida.\n\n");
			break;
		}
	}	
	if(saldoBanco == 0)
		printf("\nLo siento, tu saldo se agoto!\nYa has bebido demasiado.\n");
	else
		printf("\nHasta luego.\n");	
	system("pause");	
	return 0;
} 
	

