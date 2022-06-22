#include<stdio.h>

void ImprimeIPR(unsigned char *, unsigned char *);
void ImprimeIPB(unsigned char *, unsigned char *);
void MuestraClaseIPRB(unsigned char *, unsigned char *);

int main(){
	unsigned char MR[4] = {0,0,0,0};
	//unsigned char IP[4] = {0x0A, 0xFA, 0x01, 0x01};//IP[4] = {10,250,1,1}
	//unsigned char IP[4] = {0x96, 0x0A, 0x0F, 0x00};//IP[4] = {150,10,15,0};
	//unsigned char IP[4] = {0xC0, 0x0E, 0x02, 0x00};//IP[4] = {192,14,2,0};
	//unsigned char IP[4] = {0x94, 0x11, 0x09, 0x01};//IP[4] = {148,17,9,1};
	//unsigned char IP[4] = {0xC1, 0x00, 0x00, 0xFF};//IP[4] = {193,0,0,255};
	//unsigned char IP[4] = {0xDC, 0xC8, 0x17, 0x01};//IP[4] = {220,200,23,1};
	//unsigned char IP[4] = {0xB1, 0x64, 0x12, 0x04};//IP[4] = {177,100,18,4};
	//unsigned char IP[4] = {0x5F, 0x00, 0x15, 0x00};//IP[4] = {95,0,21,0};
	//unsigned char IP[4] = {0x6F, 0x6F, 0x6F, 0x6F};//IP[4] = {111,111,111,111};
	//unsigned char IP[4] = {0xDB, 0x1A, 0x33, 0x00};//IP[4] = {219,26,51,0};
	//unsigned char IP[4] = {0xA7, 0x00, 0x00, 0x00};//IP[4] = {167,0,0,0};
	//unsigned char IP[4] = {0x0A, 0x01, 0x01, 0x01};//IP[4] = {10,1,1,1};
	//unsigned char IP[4] = {0xE1,0x01, 0x01, 0x01};//IP[4] = {225,1,1,1};
	unsigned char IP[4] = {0xF0, 0x01, 0x01, 0x01};//IP[4] = {240,1,1,1};
	
	MuestraClaseIPRB(MR, IP);
	
	return 0;	
}	
	
void ImprimeIPR(unsigned char *MR, unsigned char *IP){ 
	printf("La direccion IP de RED es: %d.%d.%d.%d\n\n", IP[0]&MR[0], IP[1]&MR[1], IP[2]&MR[2], IP[3]&MR[3]); 
}		
	
void ImprimeIPB(unsigned char *MR, unsigned char *IP){ 
	printf("La direccion IP de BROADCAST es: %d.%d.%d.%d\n\n", (((unsigned char)IP[0])|((unsigned char)~MR[0])),
	(((unsigned char)IP[1])|((unsigned char)~MR[1])),(((unsigned char)IP[2])|((unsigned char)~MR[2])),(((unsigned char)IP[3])|((unsigned char)~MR[3])));
}	

void MuestraClaseIPRB(unsigned char *MR, unsigned char *IP){
	
	if(IP[0]&128){
		if(IP[0]&64){
			if(IP[0]&32){
				if(IP[0]&16)
					printf("\nLa direccion IP pertenece a la Clase E.\n\n");
				else
					printf("\nLa direccion IP pertenece a la Clase D.\n\n");	
			}else{
				MR[0] = 255;
				MR[1] = 255;
				MR[2] = 255;
				printf("\nLa direccion IP pertenece a la Clase C.\n\n");
				ImprimeIPR(MR, IP);
				ImprimeIPB(MR, IP);
			}
		}else{
			MR[0] = 255;
			MR[1] = 255;
			printf("\nLa direccion IP pertenece a la Clase B.\n\n");
			ImprimeIPR(MR, IP);
			ImprimeIPB(MR, IP);
		}
	}else{
		MR[0] = 255;
		printf("\nLa direccion IP pertenece a la Clase A.\n\n");
		ImprimeIPR(MR, IP);
		ImprimeIPB(MR, IP);
	}	
}






	
	
	

