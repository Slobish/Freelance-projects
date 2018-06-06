CODIGO DE PPyV

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */



#define SDC1 PTCD_PTCD3  //SENSOR DE COLOR
#define SDC2 PTCD_PTCD2  // SENSOR DE COLOR 

#define SCICLO PTBD_PTBD5 //PULSADOR DE CICLO
#define SFREC PTBD_PTBD6 //PULSADOR DE FREC

#define MULTIPLEX1 PTCD_PTCD0
#define MULTIPLEX2 PTCD_PTCD1

#define _SDC1 PTCDD_PTCDD3
#define _SDC2 PTCDD_PTCDD2

void MCU_init(char Interrupt);
void GPIO_init();
void DISPLAY_write(char d,char c,char b,char a);
void checkPorts(char numb);
void multiplex(char n);

char fase=0;

void main(void) {

MCU_init(0);

GPIO_init();
  

  for(;;) 
  { 
Switch (fase)
Case 0:
conf=0;
While (conf==0)
{
tempRead()
DISPLAY_write()
}
Break;

Case 1: 
conf=0;
While(conf==0)
{
colorRead()
DISPLAY_color()
}
Case 3:
	  
	  
    
  } 
 
}



void MCU_init(int Interrupt)
{	
	SOPT1 &= 0x3F;
	if (Interrupt) asm cli;
}

void GPIO_init()
{
	
	/*
	 	 AAAA ----> A1
A2<--- F      B ----->A0
	   F      B 
	   F GGGG B
	   E  |   C 
 B0<-- E  A3  C
	   E      C --B2
	     DDDD 	*
	       |    |
	       B1   B3
	 */  
	
	PTADD=0b00001111; 		  //PONGO PUERTO A EN SALIDA PARA DISPLAYS
		
	PTCDD=PTCDD | 0b00000011; //PONGO PUERTO C EN SALIDA PARA MULTIPLEXADO
	
	PTCDD=PTCDD & 0b11110011; //PONGO ENTRADA PUERTO C SECCION IZQ PARA SENSADO DE COLOR 
	PTBDD=PTBDD & 0b11101111; //PONGO ENTRADA B4 PARA INGRESO DE TEMPERATURA
	
	PTBDD=PTBDD & 0b10011111; //PULSADORES S1:T-->TIPO-->CICLICO Y S2:FRECUENCIA 
}







void DISPLAY_write(char d, char c,char b,char a)
{
	char n=0;
	char msg[4];
	msg[0]=a;
	msg[1]=b;
	msg[2]=c;
	msg[3]=d;
	for(n=0;n<=4;n++)
	{
		checkPorts(msg[n]);
		multiplex(n);		
	}
		
}



void multiplex(char n)
{
	switch (n)
	{
	case 0:
		MULTIPLEX1=0;
		MULTIPLEX2=0;
		break;
	case 1:
		MULTIPLEX1=1;
		MULTIPLEX2=0;
		break;
	case 2:
		MULTIPLEX1=0;
		MULTIPLEX2=1;
		break;
	case 3:
		MULTIPLEX1=1;
		MULTIPLEX2=1;
		break;

	}
}
void checkPorts(int numb)
{
	if (numb==0)
	{
		PTAD=0b00000000;		
	}
	
	if (numb==1)
	{
		PTAD=0b00000001;
		
	}
	
	if (numb==2)
	{
		PTAD = 0b00000010;		
	}
	
	if (numb==3)
	{
		PTAD = 0b00000011;		
		
	}
	if (numb==4)
	{
		PTAD=0b00001000;		
	}
	if (numb==5)
	{
		PTAD=0b00000101;		
	}
	if (numb==6)
	{
		PTAD=0b00000110;		
	}
	if (numb==7)
	{
		PTAD=0b00000111;		
	}
	if (numb==8)
	{
		PTAD=0b00001000;
	}
	if (numb==9)
	{		
		PTAD=0b00001001;
			
	}
}

//GUARDA TEMPERATURA EN VECTOR
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char i;
    int temp=1953;
    int resto=0;
    char vecto[4];
 for(i = 0;i<4;i++)
    {
resto = temp % 10; // es el resto resultante de hacer 1234/10 = 4
vecto[i] = resto;
temp = temp / 10; // dividimos 1234/10 para que nos quede el numero 123
}

printf("%d",vecto[3]);

printf("%d",vecto[2]);

printf("%d",vecto[1]);

printf("%d",vecto[0]);

}



