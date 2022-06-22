#include "ArBin.h"

typedef ArBin DicBin;

DicBin InsOrdDB(Elem e, DicBin a){
       if(EsNuevoAB(a))
            return consAB(e,nuevoAB(),nuevoAB());
       else if(EsMoI(e,raiz(a)))
                return consAB(raiz(a),InsOrdDB(e,izquierdo(a)), derecho(a));
            else
                return consAB(raiz(a),izquierdo(a),InsOrdDB(e,derecho(a)));
    }


DicBin ElimDicBin(Elem e, DicBin a){
    if(EsIgual(e,raiz(a)))
        if(EsHoja(a))
            return nuevoAB();
        else if (EsNuevoAB(derecho(a)))
                return izquierdo(a);
             else if(EsNuevoAB(izquierdo(a)))
                        return derecho(a);
                  else
                     return consAB(MasDer(izquierdo(a)),ElimDicBin(MasDer(izquierdo(a)),izquierdo(a)),derecho(a));
    else if(EsMoI(e,raiz(a)))
              return consAB(raiz(a),ElimDicBin(e,izquierdo(a)),derecho(a));
         else
              return consAB(raiz(a),izquierdo(a),ElimDicBin(e,derecho(a)));
}

int EstaEn(Elem e, DicBin a){
    if(EsNuevoAB(a))
        return 0;
    else if(EsIgual(e,raiz(a)))
             return 1;
         else
             return EstaEn(e,izquierdo(a))||EstaEn(e,derecho(a));
}
