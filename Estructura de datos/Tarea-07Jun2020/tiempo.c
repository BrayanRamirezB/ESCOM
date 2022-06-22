#include<stdio.h>
#include<time.h>
#include <windows.h>



int main(){
    time_t ti, tf;
    int i;

    ti=time(NULL);

    printf("Tiempo en segundo: %d.\n",ti);

    //for(i=1;i<=1000000;i++);

    

    tf=time(NULL);

    printf("Tiempo en segundo: %d.\n",tf-ti);

    return 0;
}
