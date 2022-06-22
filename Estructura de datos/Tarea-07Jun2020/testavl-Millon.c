#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>
#include "Elem.h"
#include "AVL.h"


int main(){
	time_t ti, tf;
    int i;
    
    ti=time(NULL);

    printf("Tiempo en segundo: %d.\n",ti);
 //   AVL a=InsAVL(30,InsAVL(10,InsAVL(20,nuevoAB())));
 //   AVL a=InsOrdDB(5,InsOrdDB(10,InsOrdDB(20,InsOrdDB(1000,InsOrdDB(200,InsOrdDB(30,nuevoAB()))))));
//    AVL a=InsAVL(5,InsAVL(10,InsAVL(20,InsAVL(1000,InsAVL(200,InsAVL(30,nuevoAB()))))));

    AVL a = nuevoAB();
    Elem e;
    srand(time(NULL));

    for(i=100;i<=500;i+=100){
        a=InsAVL(rand(),a);
        printf("%d\n",i);
    }
    EsAVL(a)?printf("Es AVL.\n"):printf("No es AVL.\n");
	printf("Altura izq = %d\t Altura der = %d\t FactBal = %d\n",AlturaAB(izquierdo(a)), AlturaAB(derecho(a)), FactBal(a));
	tf=time(NULL);
    printf("Tiempo en segundo: %d.\n",tf-ti);	
    return 0;
}
