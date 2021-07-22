/* 
 * File:   main.c
 * Author: sergi
 *
 * Created on 13 de octubre de 2020, 11:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#define _XTAL_FREQ 2000000UL
#include "configuracion.h"

/*
 * 
 */
int cont;
void conf(void);

int main(int argc, char** argv) {
    
    ANSELB=0;
    ANSELD=0;
    
    TRISD=0; //SALIDA
    conf();
    
    while(1){
        PORTD = cont;
    }
    

    return (EXIT_SUCCESS);
}

void conf(void){
    TRISBbits.RB0=1;//ENTRADA
    INTCONbits.INT0IE=1;//INTCON ES UN REGISTRO Y EL INTIE HABILITA INTERRUPCIONES
    INTCONbits.INT0IF=0;//LA BANDERA PA ABAJO,AUN NO SUCEDE LA interrupcion
    INTCON2bits.INTEDG0=0;//FLANCO DESCENDENTE
    INTCONbits.GIE=1;
}



void __interrupt() first_int(void){
    cont++;
    INTCONbits.INT0IF=0;//YA SUCEDIO HAY Q BAJARLO OTRA VEZ
}
