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
#include "LCD.h"
/*
 * 
 */
void oscilador(void);


int main(int argc, char** argv) {
    oscilador();
    ANSELD=0;
    ANSELE=0;
    TRISD=0;
    TRISE=0;

    begin();
    create(1,0x00,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00);
    setCursor(1,1);
    print("ELLA NO TE AMA");
    __delay_ms(2000);
    setCursor(4,2);
    print("MARRANOS");
    __delay_ms(2000);
    writecaracter(1);
    
    while(1){
    }
    return (EXIT_SUCCESS);
}
void oscilador(void){
    OSCCON=0X40;
    OSCCON2=0X00;
}

