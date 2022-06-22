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
