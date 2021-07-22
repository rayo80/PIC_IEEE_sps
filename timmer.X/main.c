/* 
 * File:   main.c
 * Author: zelkairi
 *
 * Created on 23 de octubre de 2020, 11:40 PM
 */

#include <stdio.h>
#include <pic18f45k50.h>
#include <stdlib.h>
#include <xc.h>
#include "configuracion.h"
#define _XTAL_FREQ 2000000

int cont=0;
void oscilador(void);
void Registros(void);

int main(int argc, char** argv) {
    oscilador();
    Registros();
    while(1){      
    }
    return (EXIT_SUCCESS);
    
}

void oscilador(void){
    OSCCON=0x40;
    OSCCON2=0x00;
}

void __interrupt() TMR_0(){
    if(INTCONbits.TMR0IF==1){
    INTCONbits.TMR0IF=0;
    cont++;
    if(cont==10){
        cont=0;
        PORTDbits.RD0=~PORTDbits.RD0;
    }    
    TMR0=131;
    //TMR0H=0b00011100;
    //TMR0L=0b10110000;
    
    }
}
void Registros(void){
    ANSELDbits.ANSD0=0;
    TRISDbits.RD0=0;
    PORTDbits.RD0=0;
    
    //habilitar interrupciones
    INTCONbits.GIE=1;
    INTCONbits.TMR0IF=0;
    INTCONbits.TMR0IE=1;
    //conf timmer
    T0CONbits.T08BIT=1; //TIMMER DE 8BITS //si lo ppones en 0 se pone automaticamente en 16
    T0CONbits.T0CS=0; //interno o externo el cristal.
    T0CONbits.T0SE=0; //FLANCO DE BAJADA
    T0CONbits.PSA=0;  //HABILITA EL PRESCALER en 16bits para 100ms se desactiva
    T0CONbits.T0PS=0b001;  //EL PRESCALER
    T0CONbits.TMR0ON=1; //HABILITO EL TIMMER
    
    TMR0=131; //CARGA ,EMPEZARA A CONTAR DESDE 132
    //para 16bits 15536 lo pasamos a binario
    //desactivar arriba 
    
    //TMR0H=0b00111100;
    //TMR0L=0b10110000;  //la union es 15536 en binario
    
    
}