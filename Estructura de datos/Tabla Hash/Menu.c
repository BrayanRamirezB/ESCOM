#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Elem.h"
#include"Lista.h"
#include"TablaH.h"
#include"FB.h"

int main(){
	int n=53;
    TablaH t=consH(n);

    t=llenavacia(n,t);
	t=TablaP(t);
	menu(n,t);
	
	return 0;
}


