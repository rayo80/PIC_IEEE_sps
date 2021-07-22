
#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#include "configuracion.h"
#include "EUSART.h"
#include "ADC.h"
//agregamos esta libreria
#include <string.h>
#define _XTAL_FREQ 8000000


void oscilador(void);
int valor1,valor2;
char valor1_c[10],valor2_c[10];


int main(int argc, char** argv) {
    ANSELC=0;
    ANSELD=0;
    TRISD=0;
    oscilador();
    serial_begin(9600);
    ADC_begin();
    
    while(1){
        //serial_print('A');
        valor1=analogRead(adc_A0);
        valor2=analogRead(adc_B0);  
        sprintf(valor1_c,"%u",valor1);
        sprintf(valor2_c,"%u",valor2);
        
       //uso de una funcion de string
        strcat(valor1_c," y el ");
        strcat(valor1_c,valor2_c);
       // serial_trama(valor1_c);
       //serial_print(valor1);//para enviar a simulnik
        __delay_ms(1000);

    }
    return (EXIT_SUCCESS);
}

void oscilador(void){
    OSCCON=0x60; //se cambia a8MGHZ
    OSCCON2=0x00;
}
