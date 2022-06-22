#include <stdio.h>

int Minimo(int , int );
int RaicesM(int , int *);

int main(){
	FILE *pf = fopen("Muestra.csv","at");
	int n, i, pts = 1, ct;
	srand(time(NULL));
	
	for(i = 0; i<=pts; i++){
		ct = 0;
		n = 3;//rand()%100000;
		printf("El minimo numero de raices es para %d es: %d", n, RaicesM(n, &ct));
		printf("\n Numero de pasos: %d\n\n",ct);
		fprintf(pf,"%d,%d\n\n", n, ct);
	}
	fclose(pf);
	 
    return 0;
}
 
int Minimo(int x, int y){//Funcion que devuelve el minimo de dos enteros
    if(x < y)
    	return x;
    else
		return y;	
}

int RaicesM(int n, int *ct){// Funcion para encontrar el numero minimo de cuadrados que suman n
    // creamos un arreglo auxiliar T, donde T[i] almacena el numero minimo de cuadrados que suman i
    int T[n+1], i, j;(*ct)++;(*ct)++;(*ct)++;
 
    // llenamos el arreglo auxiliar T con el enfoque bottom-up
    (*ct)++;
    for (i = 0; i <= n; i++){
        // inicializamos T con el maximo numero de cuadrados posible
        (*ct)++;
		T[i] = i;(*ct)++;
        // Recorremos todos los enteros positivos menores o iguales a la raíz cuadrada de i
        (*ct)++;
		for(j = 1; j*j <= i; j++){
            //calculamos el valor de T[i] utilizando el resultado de un menor subproblema T [i-j×j]
            (*ct)++;
            (*ct)++;
			T[i] = Minimo(T[i], 1 + T[i - j*j]);
        }
        (*ct)++;
    }
    (*ct)++;
    (*ct)++;
    return T[n];
}

/*
int RaicesM(int n){
    int T[n+1], i, j;
 
    for (i = 0; i <= n; i++){
        T[i] = i;
        for(j = 1; j*j <= i; j++){
            /
            T[i] = Minimo(T[i], 1 + T[i - j*j]);
        }
    }
    return T[n];
}

*/ 

