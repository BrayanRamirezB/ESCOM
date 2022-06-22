#include<stdio.h>

unsigned char RecogeC();
unsigned char CuentaBits(unsigned char caracter, unsigned char bits);

int main(){
	unsigned char bits = 0;
	unsigned char caracter = RecogeC();
			
	bits = CuentaBits(caracter, bits);
	printf("\nTiene %d bits encendidos.\n", bits);
	return 0;
}

unsigned char RecogeC(){
	printf("Ingresa un caracter\n");
	return getchar();
}

unsigned char CuentaBits(unsigned char caracter, unsigned char bits){
	unsigned char i;
	
	for(i = 128;i >= 1;i = i>>1){
		if(caracter&i)
			bits++;	
	}
	return bits;
}
