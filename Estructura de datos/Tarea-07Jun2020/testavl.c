#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "AVL.h"


int main(){

 //   AVL a=InsAVL(30,InsAVL(10,InsAVL(20,nuevoAB())));
 //   AVL a=InsOrdDB(5,InsOrdDB(10,InsOrdDB(20,InsOrdDB(1000,InsOrdDB(200,InsOrdDB(30,nuevoAB()))))));
//    AVL a=InsAVL(5,InsAVL(10,InsAVL(20,InsAVL(1000,InsAVL(200,InsAVL(30,nuevoAB()))))));
    AVL a = nuevoAB();
    Elem e;

    while(e=LeeElem()){
    	system("cls");
        a=InsAVL(e,a);
        ImpNivelPorNivelAB(a);
        puts("-----");
        printf("Altura izq = %d\t Altura der = %d\t FactBal = %d\n",AlturaAB(izquierdo(a)), AlturaAB(derecho(a)), FactBal(a));
        puts("-----");
        EsAVL(a)?printf("Es AVL.\n"):printf("No es AVL.\n");
    }
    return 0;
}
