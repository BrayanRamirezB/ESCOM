#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Elem.h"
#include"Lista.h"
#include"TablaH.h"

int main(){


     int i,j, n=5;
     TablaH t=consH(5);

     for(i=0;i<n;i++)
        t[i]=vacia();

     for(i=0;i<n;i++)
        for(j=1;j<=n;j++)
            t[i]=cons(j*(i+1),t[i]);

     for(i=0;i<n;i++){
        ImpLista(t[i]);
        puts("");
     }

     return 0;
}

   /*
    Elem f,e,s;
    
    e=LeeElem(e);
    t=insertaH(Deterllave(e),e,t);
	s=LeeElem(s);
	t=insertaH(Deterllave(s),s,t);
	
	f=consulta(Deterllave(r),t);
	ImpElem(f);    
    printf("%d",estaenH(Deterllave(e),t));
    printf("%d",estaenH(100,t));
	
    for(i=0;i<n;i++){
       ImpLista(t[i]);
       puts("");
    }

	ImpLista(t[4]);
	puts("");
	t=elimina(Deterllave(e),t);
	ImpLista(t[4]);
    Elem e;
	e=LeeElem(e);
	ImpElem(e);
	printf("%d",Deterllave(e));
	*/
