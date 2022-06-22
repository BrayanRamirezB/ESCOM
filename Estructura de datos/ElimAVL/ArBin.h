typedef struct Nodo{
        Elem dato;
        struct Nodo *izq;
        struct Nodo *der;
        }*ArBin;

ArBin nuevoAB(){ return NULL;}

ArBin consAB(Elem r, ArBin i, ArBin d){
    ArBin t = (ArBin)malloc(sizeof(struct Nodo));
    t->dato=r;
    t->izq=i;
    t->der=d;
    return t;
}

int EsNuevoAB(ArBin a){return a == NULL;}

Elem raiz(ArBin a){ return a->dato;}

ArBin izquierdo(ArBin a){ return a->izq;}

ArBin derecho(ArBin a){ return a->der;}

int EsHoja(ArBin a){
    return (EsNuevoAB(izquierdo(a))&&EsNuevoAB(derecho(a)));
}

int Mayor(int n1, int n2){
     if(n1>=n2)
        return n1;
     else
        return n2;
}

int AlturaAB(ArBin a){
    if(EsNuevoAB(a))
          return 0;
    else
          return 1+Mayor(AlturaAB(izquierdo(a)),AlturaAB(derecho(a)));
}

int PesoAB(ArBin a){
     if(EsNuevoAB(a))
          return 0;
     else
          return 1+PesoAB(izquierdo(a))+PesoAB(derecho(a));
}

Elem MasDer(ArBin a){
    if(EsHoja(a))
        return raiz(a);
    else if(EsNuevoAB(derecho(a)))
             return raiz(a);
         else return MasDer(derecho(a));
}

void ImpInOrdAB(ArBin a){
      if(!EsNuevoAB(a)){
        ImpInOrdAB(izquierdo(a));
        ImpElem(raiz(a));
        ImpInOrdAB(derecho(a));
      }
}

void ImpNivelAB(ArBin a, int nivel)
{
    if (EsNuevoAB(a))
        return;
    if (nivel == 1)
        printf("%d ", raiz(a));
    else if (nivel > 1)
    {
        ImpNivelAB(izquierdo(a), nivel-1);
        ImpNivelAB(derecho(a), nivel-1);
    }
}

void ImpNivelPorNivelAB(ArBin a)
{
    int h = AlturaAB(a);
    int i;
    for (i=1; i<=h; i++)
    {
        ImpNivelAB(a, i);
        printf("\n");
    }
}
