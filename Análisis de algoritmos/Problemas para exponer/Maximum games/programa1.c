#include <stdio.h> 
  
int MaxJuegosG(int , int *);

// Driver code to test above methods 
int main(){
	FILE *pf = fopen("Muestra.csv","at");
	int n, i, pts = 1000, ct;
 
	for(i = 0; i<=pts; i++){
		ct = 0;
		n = i;
		printf("Jugadores %d: %d \n", n, MaxJuegosG(n, &ct)); 
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
	}
	fclose(pf);
   
    return 0; 
} 

// La función devuelve el maximo numero de juegos que necesita un ganador.
// para jugar en un torneo de n jugadores

int MaxJuegosG(int n, int *ct){ 
    int J[n], i = 2; (*ct)++;(*ct)++;
  
    J[0] = 1;(*ct)++;
    J[1] = 2;(*ct)++;
    (*ct)++;   
    do { 
    	(*ct)++;
    	(*ct)++;
        J[i] = J[i - 1] + J[i - 2]; 
    } while (J[i++] <= n);(*ct)++;
	(*ct)++; 
    (*ct)++;
    return (i - 2); 
} 

/*
int MaxJuegosG(int n){ 
    int J[n], i = 2; 
  
    J[0] = 1;// para 0 juegos, se necesita 1 jugador
    J[1] = 2;// Para 1 juego, se requieren 2 jugadores
       
    do { //hasta que el número i-ésimo de Fibonacci sea menor o igual a n
        J[i] = J[i - 1] + J[i - 2]; 
    } while (J[i++] <= n); 
  
    return (i - 2); 
} 
*/
