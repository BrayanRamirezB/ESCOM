/*INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
MATERIA: ANÁLISIS DE ALGORITMOS
ALUMNO: BRAYAN RAMIREZ BENITEZ
GRUPO: 3CV11
PROFESOR: LUNA BENOSO BENJAMIN
SEMESTRE: 2022-1*/
#include <stdio.h>
#include <stdlib.h>
//---------------------------------Estructuras para el programa------------------------

typedef struct Arista{//definimos la estructura para la aristas
	int nd1, nd2;
} Art;

typedef struct Grafo{//definimos la estructura del grafo
	int nds[100];
	Art art[100];
} Grafo;

typedef struct Certificado{//definimos la estructura del certificado
	int nd[100];	
} certificado;

//---------------------------------Funciones para el programa------------------------

void ImpCtf(certificado );
void ImpGrf(Grafo );
void RecogeG(Grafo *);
void RecogeC(certificado *);
int TamCtf(certificado );
int TamGrf(Grafo );
void LlenaArreglo(int *, int);
int VerificacionHamilton(Grafo , certificado , int *);

//---------------------------------Programa------------------------

int main(){
	FILE *pf = fopen("Muestra.csv","at");
	int i, n, ct;
	Grafo G;
	certificado C[100];
	
	RecogeG(&G);
	RecogeC(C);
	n = TamGrf(G);
	
	for(i = 0 ;C[i].nd[1] != 0; i++){
		ct = 0;
		ImpCtf(C[i]);
		
		if(VerificacionHamilton(G, C[i], &ct))
			printf("Si es un ciclo hamiltoniano.\n");
		else
			printf("No es un ciclo hamiltoniano.\n");
		printf("Numero de pasos: %d\n\n", ct);
		fprintf(pf,"%d,%d\n\n", n, ct);	//Enviamos los datos al documento
	}
	fclose(pf);
			
	return 0;
}

void ImpCtf(certificado C){//Imprime un certificado
	int i;
	
	printf("El certificado: ");
	for(i = 0 ;(C.nd[i]) != 0; i++)
		printf("%d ", C.nd[i]);
	puts("");
}

void ImpGrf(Grafo G){//Imprime un grafo
	int i;

	for(i = 0 ;i < 10; i++)
		printf("%d ", G.nds[i]);

	puts("");
  
	for(i = 0 ;i < 55; i++)
		printf("(%d,%d)\n", G.art[i].nd1, G.art[i].nd2);
}

void RecogeG(Grafo *G){//Lee un grafo de un archivo txt
	FILE *doc = fopen("g11.txt","r");
	
	int i;
	char c;
  
	for(i = 0 ;i < 10; i++)
		G->nds[i] = 0;
	
	for(i = 0 ;i < 55; i++){
		G->art[i].nd1 = 0;
		G->art[i].nd2 = 0;
	}
	
	i = 0;
	while((c = fgetc(doc)) != '\n'){
		if(c != ' '){
			G->nds[i] = c-'0';
			i++;
		}
	}
	
	i = 0;
	while((c = fgetc(doc)) != EOF){
		G->art[i].nd1 = c-'0';
		c = fgetc(doc);
		c = fgetc(doc);
		G->art[i].nd2 = c-'0';
		c = fgetc(doc);
		i++;
	}
	
	fclose(doc);
}

void RecogeC(certificado *C){//Lee un certificado de un archivo txt
	FILE *doc = fopen("cr11.txt", "r");
	int i, j;
	char e;
	
	for(i = 0 ;i < 10; i++){
		for(j = 0 ;j < 25; j++){
			C[i].nd[j] = 0;
		}
	}

	i = 0;
	j = 0;
	
	while((e = fgetc(doc)) != EOF){
		if(e == '\n'){
			i++;
			j = 0;
		}else if(e != ' '){
			C[i].nd[j] = e - '0';
			j++;
		}
	}
	 
	fclose(doc);
}

int TamCtf(certificado C){//Devuelve el tamaño del certificado
	int i;
	
	for(i = 0; C.nd[i] != 0; i++);
	return i;
}

int TamGrf(Grafo G){//Devuelve el tamaño del certificado
	int i;
	
	for(i = 0; G.nds[i] !=0 ; i++);
	return i;
}

void LlenaArreglo(int *A, int num){//Llena con un numero un arreglo
	int i;
	
	for(i = 0 ;i < 100; i++)
		A[i] = num;
	
}

int VerificacionHamilton(Grafo G, certificado C, int *ct){
	int i, j, pruebas[100], marcador;(*ct)++;(*ct)++;(*ct)++;(*ct)++;
	int tamcr = TamCtf(C);(*ct)++;
	int tamg = TamGrf(G);(*ct)++;
	
	LlenaArreglo(pruebas, 0);(*ct)++;
		
	if(tamcr != (tamg + 1) || C.nd[0] != C.nd[tamg]){ 
		(*ct)++;			
		return 0;
	}(*ct)++;
	
 	(*ct)++; 
	for(j = 0 ;j < tamcr-1; j++){
		(*ct)++;
		marcador = 0;
		for(i = 0 ;i < 100; i++){
			(*ct)++;
			if(G.art[i].nd2 == C.nd[j+1] && G.art[i].nd1 == C.nd[j] ){
				(*ct)++;
				(*ct)++;
				marcador = 1; 
				break;
    	  	}
      		if(G.art[i].nd2 == C.nd[j] && G.art[i].nd1 == C.nd[j+1]){
       		 	(*ct)++;
				(*ct)++;
				marcador = 1; 
       			break;
     		}
    	}
    	(*ct)++;
    	if(marcador == 0){
			(*ct)++;
			(*ct)++;
			return 0;
    	}
    	if(pruebas[C.nd[j]-1] == 0){
    		(*ct)++;
    		(*ct)++;
			pruebas[C.nd[j]-1] = 1;
    	}else{
			(*ct)++;
			(*ct)++;
			return 0;
	    }
  	}
  	(*ct)++;
	
	(*ct)++;
	for(i = 0 ;i < tamg; i++){
		(*ct)++;
		if(pruebas[i] == 0){ 
			(*ct)++;
			(*ct)++;
			return 0;
		}
	}
	(*ct)++;
	return 1;(*ct)++;
}



/*Código sin comentarios

int VerificacionHamilton(Grafo G, certificado C, int *ct){//Verifica si el certificado es hamiltoniano
	int i, j, marcador, pruebas[100];
	int tamcr = TamCtf(C);
	int tamg = TamGrf(G);
	
	LlenaArreglo(pruebas, 0);//Colocamos las pruebas en 0
		
	if(tamcr != (tamg + 1) || C.nd[0] != C.nd[tamg])//Revisamos si cumple para ser hamiltoniano 			
		return 0;
	
	for(j = 0 ;j < tamcr-1; j++){//Revisamos el certifcado
		marcador = 0;
		
		for(i = 0 ;i < 100; i++){//Revisamos si existe un camino
			if(G.art[i].nd2 == C.nd[j+1] && G.art[i].nd1 == C.nd[j]){
				marcador = 1; 
				break;
    	  	}
      		if(G.art[i].nd2 == C.nd[j] && G.art[i].nd1 == C.nd[j+1]){
				marcador = 1; 
       			break;
     		}
    	}
    	
    	if(marcador == 0)//Confirmamos si existe un camino
			return 0;
			
    	if(pruebas[C.nd[j]-1] == 0)//Colocamos pruebas de haber pasado por un nodo
			pruebas[C.nd[j]-1] = 1;
    	else//En caso de pasar por un mismo nodo ya no es un ciclo hamiltoniano
			return 0;  
  	}
	
	for(i = 0 ;i < tamg; i++){//Revisamos si pasamos por todos los nodos
		if(pruebas[i] == 0)
			return 0;	
	}
	return 1;
}
*/











