#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "AVL.h"


int main(){
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
    //Para terminar el ciclo ingrese un 0
	    
	puts("-----");
    printf("Que elemento desea borrar?.\n");
    a=ElimAVL(LeeElem(),a);
    puts("-----");
    
    //La función ElimAVL pregunta si el elemento se encuentra, ademas de por supuesto eliminar  el elemento en caso de encontrarse.
    
	ImpNivelPorNivelAB(a);
    puts("-----");
    printf("Altura izq = %d\t Altura der = %d\t FactBal = %d\n",AlturaAB(izquierdo(a)), AlturaAB(derecho(a)), FactBal(a));
    puts("-----");
    EsAVL(a)?printf("Es AVL.\n"):printf("No es AVL.\n");
    return 0;
}
