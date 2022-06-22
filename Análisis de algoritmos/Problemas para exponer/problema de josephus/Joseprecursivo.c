#include <stdio.h>
 
int josephus(int n, int k){
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}
 

int main()
{
    int n = 41;
    int k = 2;
    printf("El soldado sobreviviente es %d", josephus(n, k));
    return 0;
}
