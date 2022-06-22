#include <stdio.h>
#define TAM 10000

void ImpArreglo(int *, int );
void LlenaArreglo(int *, int );
void InsertionSort(int *, int );
int Maximo(int , int );
int rodC(int *, int , int *);
const int INF = 100000;

int main() {
	FILE *pf = fopen("Muestra.csv","at");
	int ct, pts = 100, i, n = 10;
	int C[TAM];
	
    // matriz a partir de 1, el elemento en el índice 0 es falso
    for(i = 0; i<pts ; i++){	
		ct = 0;
		LlenaArreglo(C, n);
  		ImpArreglo(C, n);
    	printf("\nBeneficio maximo despues de vender: %d\n", rodC(C, n, &ct));
		printf("\n\nNumero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);	//Enviamos los datos al documento
		n+=10;
	}	
	fclose(pf);			
    
    return 0;
}

int Maximo(int x, int y){
	if(x > y)
		return x;
	else
		return y;	
}

void LlenaArreglo(int *A, int n){//Llena un arreglo con valores aleatorios y los ordena
	srand(time(NULL));
	int i;
	A[0] = 0;
	
	for(i = 1;i<=n;i++)
		A[i] = rand()%(1000);
	
	InsertionSort(A, n);
}

void InsertionSort(int *A, int n){// ordena un arreglo
	int i, j, key;
	
	for(i = 1; i<=n ; i++){
		key = A[i];
		j = i-1;
		
		while(j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

void ImpArreglo(int *A, int n){
	int i;
	
	for(i = 1; i<=n ; i++)
		printf("%d ", A[i]);
		
}

int rodC(int C[], int n, int *ct) {
  int R[n+1], i, j;(*ct)++;(*ct)++;(*ct)++;

  R[0] = 0;(*ct)++;
  (*ct)++;	
  for(j = 1; j <= n; j++) {
  	(*ct)++;
  	(*ct)++;
    int mb = -1*INF;
    (*ct)++;
    for(i=1; i <= j; i++) {
      (*ct)++;
      (*ct)++;
	  mb = Maximo(mb, C[i] + R[j-i]);
    }
    (*ct)++;
    R[j] = mb;(*ct)++;
  }(*ct)++;
  (*ct)++;
  return R[n];
}
/*

int rodC(int P[], int n) {
  int B[n+1], i, j;

  B[0] = 0;
  
  for(j = 1; j <= n; j++) {
    int mb = -1*INF;
    
    for(i=1; i <= j; i++) {
	  mb = Maximo(mb, P[i] + B[j-i]);
    }
    B[j] = mb;
  }
  return B[n];
}

*/

