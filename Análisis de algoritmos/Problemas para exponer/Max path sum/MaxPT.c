#include<stdio.h> 
#define N 100 
  
int MaxCS(int A[][N], int , int *);
void LlenaArreglo(int A[][N], int );
void ImprimeArreglo(int A[][N], int );
  
int main() {
	FILE *pf = fopen("Muestra.csv","at");
	int A[N][N], n, i, pts = 90, ct;
	
	
	for(i = 1; i<=pts; i++){
		ct = 0;
		n = i;
		LlenaArreglo(A, n);
		ImprimeArreglo(A, n);
		printf("Suma del maximo camino: %d \n", SumMC(A, n, &ct)); 
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
		puts("");
	}
	fclose(pf);
    
    return 0;
}

void LlenaArreglo(int A[][N], int n){
	srand(time(NULL));
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			
			if(j <= i){
				A[i][j] = rand()%100;		
			}else{
				A[i][j] = 0;	
			}
		}
	}
} 

void ImprimeArreglo(int A[][N], int n){
	int i, j;
	
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			printf("%d ", A[i][j]);
		}
		puts("");
	}
}

int SumMC(int A[][N], int n, int *ct){//Funcion para encontrar la suma
    int i, j;(*ct)++;(*ct)++;
    
    (*ct)++;
    for (i = n ;i >= 0; i--){//ciclo para el calculo ascendente
    	(*ct)++;
    	(*ct)++;
		for (j = 0 ;j <= i; j++){
			(*ct)++;  
            if (A[i+1][j] > A[i+1][j+1]){
            	(*ct)++;
                A[i][j] = A[i][j] + A[i+1][j];
			}else{
            	(*ct)++;
                A[i][j] = A[i][j] + A[i+1][j+1]; 
        	}(*ct)++;
		}
		(*ct)++; 
    }
	(*ct)++; 
     (*ct)++;
    return A[0][0];//devuelve el elemento superior que almacena la suma máxima
} 

int SumMC(int A[][N], int n){
    int i, j;
    
    for (i = n ;i >= 0; i--){
		for (j = 0 ;j <= i; j++){  
            if (A[i+1][j] > A[i+1][j+1]) 
                A[i][j] = A[i][j] + A[i+1][j]; 
            else
                A[i][j] = A[i][j] + A[i+1][j+1]; 
        } 
    } 
     
    return A[0][0];
} 
*/
