#include <stdio.h>

// Las uniones se declaran de la misma forma que las structs
union test {
int x, y;
};

int main(){
// Definimos la variable t de tipo union test
union test t;

t.x = 2; // t.y también toma el valor de 2
printf("Despues de hacer x = 2:\n x = %d, y = %d\n\n", t.x, t.y);

t.y = 10; // t.x también es actualizada con el valor 10
printf("Despues de hacer y = 10:\n x = %d, y = %d\n\n", t.x, t.y);

return 0;
}
