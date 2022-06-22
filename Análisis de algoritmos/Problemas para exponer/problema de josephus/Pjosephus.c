#include<stdio.h>

int Josephus(int , int , int *);

int main(){
	
	FILE *pf = fopen("Muestra.csv","at");
	int n, i, pts = 1000, ct;
	srand(time(NULL));
	
	for(i = 0; i<pts; i++){
		ct = 0;
		n = rand()%1000000;
		
		printf("n = %d y k = %d el sobrevivivente es: %d\n", n, 2, Josephus(n, 2, &ct));
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
	}
	fclose(pf);
	
	return 0;
}

int Josephus(int n, int k, int *ct){
	int res = 0, i;(*ct)++;(*ct)++;
	
	(*ct)++;
	for(i = 1; i<= n; ++i){
		(*ct)++;
		(*ct)++;
		res = (res + k - 1) % i + 1;
		(*ct)++;
	}
	(*ct)++;
	(*ct)++;	
	return res;	
}






