#include<stdio.h>

unsigned int CuentaP(int , int *);

int main() {
	FILE *pf = fopen("Muestra.csv","at");
	int n, i, pts = 20, ct;
	
	
	for(i = 0; i<pts; i++){
		ct = 0;
		n = i;
	    printf("Numero de formas para emparejar %d amigos es: %d", n, CuentaP(n, &ct));
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
	}
	fclose(pf);

	return 0;
}

unsigned int CuentaP(int n, int *ct) {
   unsigned int P[n + 1], i;(*ct)++;(*ct)++;//numero de pares para el i-esimo numero y el iterador

   //para los numeros 0 a 2, hay 0 a 2 combinaciones posibles
   P[0] = 0;(*ct)++;
   P[1] = 1;(*ct)++;
   P[2] = 2;(*ct)++;

	(*ct)++;
    for (i = 3; i <= n; i++){//llena el arreglo de 3 hasta n numeros
      (*ct)++;
      (*ct)++;
	  P[i] = (i-1) * P[i-2] + P[i-1];
	}
	(*ct)++;
	(*ct)++;
   return P[n];
}


/*
int CuentaP(int n) {
   int P[n + 1], i;

   P[0] = 0;
   P[1] = 1;
   P[2] = 2;

   for (i = 3; i <= n; i++)
      P[i] = (i-1) * P[i-2] + P[i-1];

   return P[n];
}

*/
