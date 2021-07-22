/* 
 * File:   main.c
 * Author: sergi
 *
 * Created on 6 de octubre de 2020, 02:54 AM
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

void oscilador(void);
void incrementador(void);
void decrementador(void);
int unidades[10]={0X3F,0X06,0X5B,0x4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
int decenas[10]={0X3F,0X06,0X5B,0x4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
int cuenta=0;

int main(int argc, char** argv) {
    oscilador();
    TRISD=0b00000000;
    TRISA=0;
    ANSELB=0; //PARA HACERLO DIGITAL ,PUES NO FUNCIONARA SINO
    TRISBbits.RB0=1;
    TRISBbits.RB0=1; 
    /*while(1){
        for (int k=0;k<10;k++){
            PORTA=decenas[k];          
            for(int i=0;i<10;i++){
               PORTD=unidades[i];
               __delay_ms(500);
            }
        }
    }*/
    while(1){
        if (PORTBbits.RB0==1){
            incrementador();
        }
        if (PORTBbits.RB1==1){
            decrementador();
        }
    }
    return (EXIT_SUCCESS);
}
void oscilador(void){
    OSCCON=0X40;
    OSCCON2=0X00;
}
void incrementador(void){
    __delay_ms(30);
    while(PORTBbits.RB0==1);//se detiene el boton
    __delay_ms(30);
    cuenta++;
    PORTD=unidades[cuenta%10];
    PORTA=decenas[cuenta/10];
}
void decrementador(void){
    __delay_ms(30);
    while(PORTBbits.RB1==1);//se detiene el boton
    __delay_ms(30);
    cuenta--;
    PORTD=unidades[cuenta%10];
    PORTA=decenas[cuenta/10];
}
