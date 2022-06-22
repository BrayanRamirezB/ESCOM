#include <stdio.h>
#define LIMITE -1

void Jos(int *, int , int , int *);

int main(){
	FILE *pf = fopen("Muestra1.csv","at");
	int n, i, pts = 10, ct, j, A[100];
	srand(time(NULL));
	
	
	//for(i = 2; i<pts; i++){
		ct = 0;
		//n = rand()%1000;
		Jos(A,13, 2, &ct);
		for(j = 0;j<13;j++){//soldados vivos = 1
			printf("%d \n",A[j]);
		}
	//	printf("n = %d y k = %d el sobrevivivente es: %d\n", i, 2, 1);
	//	printf("\n Numero de pasos: %d\n\n",ct);
	//	fprintf(pf,"%d,%d\n\n", n, ct);
	//}
	fclose(pf);
	
	return 0;
}

void Jos(int *A, int n, int k, int *ct){
	int i, indice;//Arreglo con los soldados
	(*ct)++;	
	for(i = 0;i<n;i++){//soldados vivos = 1
		A[i] = 1;
	}
	
	indice = 0;
	while(n>1){
		for(i = 0;i<k;i++){//recorremos el arreglo k posiciones
			if(indice > n){//verificamos si llegamos al final del arreglo
				indice = 0;//volvemos al principio
			}
			while(A[indice]==0){
				indice++;
				if(indice > n){
					indice = 0;
				}
			}
			indice++;
		}
		A[indice-1] = 0;
		n = n-1;
	}
}




