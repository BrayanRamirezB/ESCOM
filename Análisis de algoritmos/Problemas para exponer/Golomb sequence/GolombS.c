#include <stdio.h> 

void Golomb(int , int *);
 
int main(){ 
    FILE *pf = fopen("Muestra.csv","at");
	int n, i, pts = 1000, ct;
	srand(time(NULL));
    
    for(i = 1; i<=pts; i++){
		ct = 0;
		n = i;//rand()%1000;
		Golomb(n, &ct); 
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
	}
	fclose(pf);
    
    return 0; 
} 
  

void Golomb(int n, int *ct){//Imprime los primeros n terminos de la secuencia de Golomb
    int A[n+1], i; (*ct)++;(*ct)++;
  
    // caso base 
    A[1] = 1; (*ct)++;
    printf("%d ", A[1]);(*ct)++;
	 
    // Encontramoslos primeros n términos de la secuencia de Golomb.
    (*ct)++;
    for (i = 2; i <= n; i++){
		(*ct)++; 
        A[i] = 1 + A[i - A[A[i - 1]]]; (*ct)++;
        printf("%d ", A[i]);(*ct)++;
    }
	(*ct)++; 
} 


/*

void Golomb(int n){//Imprime los primeros n terminos de la secuencia de Golomb
    int A[n+1], i;
  
    // caso base 
    A[1] = 1; 
    printf("%d ", A[1]);
	 
    // Encontramoslos primeros n términos de la secuencia de Golomb.
    for (i = 2; i <= n; i++){
        A[i] = 1 + A[i - A[A[i - 1]]]; 
        printf("%d ", A[i]);
    }
} 
*/
