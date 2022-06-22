#include "DicBin.h"

typedef DicBin AVL;

int Absoluto(int n){
     if(n>=0)
         return n;
     else
         return -n;
}

int FactBal(DicBin a){ return AlturaAB(izquierdo(a))-AlturaAB(derecho(a));}

int EsAVL(DicBin a){
    if(EsNuevoAB(a))
        return 1;
    else
        return (Absoluto(AlturaAB(izquierdo(a))-AlturaAB(derecho(a)))<=1) && (EsAVL(izquierdo(a))) && (EsAVL(derecho(a)));
}

AVL RotaIzq(DicBin a){
     return consAB(raiz(derecho(a)),consAB(raiz(a),izquierdo(a),izquierdo(derecho(a))),derecho(derecho(a)));
}

AVL RotaDer(DicBin a){
     return consAB(raiz(izquierdo(a)),izquierdo(izquierdo(a)),consAB(raiz(a),derecho(izquierdo(a)),derecho(a)));
}
AVL RotaIzqDer(DicBin a){ return RotaIzq(consAB(raiz(a),izquierdo(a),RotaDer(derecho(a))));}
AVL RotaDerIzq(DicBin a){ return RotaDer(consAB(raiz(a),RotaIzq(izquierdo(a)),derecho(a)));}

AVL HazAVL(DicBin a){
    if(Absoluto(FactBal(a))>1){
    	if(EsAVL(izquierdo(a))&&EsAVL(derecho(a))){
			if(FactBal(a)>1){
				if(FactBal(izquierdo(a))>0)
					return RotaDer(a);
				else
					return RotaDerIzq(a);
			}else{
				if(FactBal(derecho(a))<0)
					return RotaIzq(a);
				else
					return RotaIzqDer(a);	
			}
		}else{
			if(EsAVL(izquierdo(a)))
				return consAB(raiz(a),izquierdo(a),HazAVL(derecho(a)));
			else
				return consAB(raiz(a),HazAVL(izquierdo(a)),derecho(a));
		}
	}else{
		if(EsAVL(izquierdo(a)))
			return consAB(raiz(a),izquierdo(a),HazAVL(derecho(a)));
		else
			return consAB(raiz(a),HazAVL(izquierdo(a)),derecho(a));
	}
}

AVL InsAVL(Elem e, AVL a){
    a=InsOrdDB(e,a);
    if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}
