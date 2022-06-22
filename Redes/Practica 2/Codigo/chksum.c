#include<stdio.h>

unsigned short ObtenerChk(unsigned char *, unsigned char);
void VerificarChk(unsigned char *,unsigned char, unsigned short);
void MostrarChk(unsigned short);

int main(){
	unsigned short Checksum = 0;
	
	unsigned char T[20] = {0x45, 0x00, 01, 0x9c, 0xd7, 0xde, 0x40, 0x00, 0x80,
	0x06, 0x88, 0x9d, 0xc0,	0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
	
	Checksum = ObtenerChk(T, 20);
	VerificarChk(T, 20, Checksum);
	
	return 0;
}

unsigned short ObtenerChk(unsigned char *T, unsigned char tam){
	unsigned char i;
	unsigned int chk = 0x00;
	
	for(i = 0; i<tam ;i+=2){
		if(!(i == 10))
			chk += (T[i] << 8) + T[i + 1];
	}		
		
	return (~((chk&65535) + (chk >> 16)))&65535;
}

void VerificarChk(unsigned char *T, unsigned char tam, unsigned short Checksum){
	
	if(Checksum == (T[10] << 8) | T[11])
		printf("El Checksum 0x%.4x es correcto");
	else{
		printf("El Checksum 0x%.4x no es correcto\n", (T[10] << 8) + T[11]);
		MostrarChk(Checksum);
	}	
}

void MostrarChk(unsigned short Checksum){
	printf("El Checksum es: 0x%.4x\n", Checksum);
}



/*

unsigned short ObtenerChk(unsigned char *T, unsigned char tam, unsigned short Checksum){
	unsigned char i;
	T[10] = 0x00;T[11] = 0x00;
	
	for(i = 1; i<tam ;i+=2)
		Checksum += (T[i] >> 4);
		
	Checksum = (Checksum&240)>>4; 
	
	for(i = 0; i<tam;i+=2)
		Checksum += (T[i]);
	
	Checksum = (Checksum)>>8; 
	
	for(i = 0; i<tam ;i+=2)
		Checksum += (T[i] << 8) + T[i + 1];
	
	return ~(Checksum);
}

*/

	//MostrarChk(Checksum);
	//unsigned char T[20] = {0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80,
	//0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};


