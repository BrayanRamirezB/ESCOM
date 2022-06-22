#include<stdio.h>

int minimo(int , int , int );
int UglyNum(int , int *);

int main() {
	FILE *pf = fopen("Muestra.csv","at");
	int n, i, pts = 1, ct;
	srand(time(NULL));
	
	for(i = 0; i<pts; i++){
		ct = 0;
		n = 6;//rand()%1000;
	    printf("El numero feo %d es: %d", n, UglyNum(n, &ct));
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
	}
	fclose(pf);
   
   return 0;
}

int minimo(int x, int y, int z) {//Regresa el menor de 3 numeros
   if(x < y) {
      if(x < z)
         return x;
      else
         return z;
   }else {
      if(y < z)
         return y;
      else
         return z;
   }
}

int UglyNum(int n, int *ct) {
   int F[n];(*ct)++;// Arreglo para almacenar los numeros "feos"
   int i, i2 = 0, i3 = 0, i5 = 0;(*ct)++;(*ct)++;(*ct)++;(*ct)++;

   //Encontramos el siguiente múltiplo como 1*2, 1*3, 1*5
   int sigmul2 = 2, sigmul3 = 3, sigmul5 = 5;(*ct)++;(*ct)++;(*ct)++;
   
   int siguiente = 1;(*ct)++;//El primer numero feo es 1
   F[0] = 1;(*ct)++;//Agregamos el primer numero al arreglo F
	
	(*ct)++;
   for (i = 1; i<n; i++) {
   	(*ct)++;
      siguiente = minimo(sigmul2, sigmul3, sigmul5);(*ct)++;//Encontramos el siguiente numero feo
      F[i] = siguiente;(*ct)++;
		
      if (siguiente == sigmul2) {
      	(*ct)++;
         i2++;(*ct)++;//Incrementamos el iterador de numeros feos cuyo factor es 2
         sigmul2 = F[i2]*2;(*ct)++;
      }(*ct)++;

      if (siguiente == sigmul3) {
      	(*ct)++;
         i3++;(*ct)++;// Incrementamos el iterador de numeros feos cuyo factor es 3             
         sigmul3 = F[i3]*3;(*ct)++;
      }(*ct)++;

      if (siguiente == sigmul5) {
      	(*ct)++;
         i5++;(*ct)++; // aumenta el iterador de numeros feos cuyo factor es 5
         sigmul5 = F[i5]*5;(*ct)++;
      }(*ct)++;
   }
   (*ct)++;
   return siguiente;(*ct)++;// regresamos el n-esimo numero feo     
}



/*
int UglyNum(int n, int *ct) {
   int F[n];
   int i, i2 = 0, i3 = 0, i5 = 0;

   int sigmul2 = 2, sigmul3 = 3, sigmul5 = 5;
   int siguiente = 1;
   F[0] = 1;

   for (i = 1; i<n; i++) {
      siguiente = minimo(sigmul2, sigmul3, sigmul5);//Encontramos el siguiente numero feo
      F[i] = siguiente;
      
      if (siguiente == sigmul2) {
         i2++;
         sigmul2 = F[i2]*2;
      }

      if (siguiente == sigmul3) {
         i3++;        
         sigmul3 = F[i3]*3;
      }

      if (siguiente == sigmul5) {
         i5++;
         sigmul5 = F[i5]*5;
      }
   }
   return siguiente;  
}
*/























