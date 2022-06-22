#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"AVL.h"

int main(){
	Elem e;
    DicBin a=nuevoAB();

    while(e=LeeElem())
        a=InsOrdDB(e,a);

    puts("-------------");
    ImpNivelPorNivelAB(a);
    puts("-------------");

    a=ElimDicBin(LeeElem(),a);
    
    puts("-------------");
    ImpNivelPorNivelAB(a);
    puts("-------------");
    return 0;
}
//    EstaEn(175,a)?puts("Si"):puts("No");
//    ImpElem(MasDer(izquierdo(a)));
