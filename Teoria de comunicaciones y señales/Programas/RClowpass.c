#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159265359

void main(int argc, char *argv[]){
	long n = 0, N;
	char *fin;
	//double Wc = 2*PI*5000, fs = 44100, T = 1/fs;
	
	if(argc > 1)
		N = strtol(argv[1], &fin, 10);
	
	double a[2] = {0.271168, 0.271168};//{0.271168291753643   0.271168291753643}
	double b[2] = {1, -0.45766};//{1 -0.457663416492714469896441187302116304636 }
	double x[2] = {0, 0};
	double y[2] = {0, 0};
	
	do{
		x[0] = x[1];
		y[0] = y[1];
		x[1] = getchar()/256.0;
		y[1] = (a[0]*x[1])+(a[1]*x[0])-(b[1]*y[0]);
		putchar(y[0]*256.0);
		//printf("%f\n",y[1]);
		n++;
	} while (n < N);
}
