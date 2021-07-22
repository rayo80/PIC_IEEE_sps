/* 
 * File:   main.c
 * Author: sergi
 *
 * Created on 15 de octubre de 2020, 03:11 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#define _XTAL_FREQ 2000000UL
#include "configuracion.h"
#include "LCD.h"

int cont=0;
void oscilador(void);
void conf(void);
/*
 * 
 */
int main(int argc, char** argv) {
    
    oscilador();
    ANSELB=0;
    ANSELD=0;
    ANSELE=0;
    ANSELA=0;
    
    ANSELBbits.ANSB4=0;
    ANSELBbits.ANSB0=0;
    TRISBbits.RB4=1;
    TRISD=0;
    TRISA=0;
    TRISE=0;
    conf();
    begin();
    while(1){  
        
        /*
        if(PORTBbits.RB4==1){
            while (PORTBbits.RB4==1);
            cont++;
            PORTA=cont;   
        }
        */
        PORTD=255;
        __delay_ms(1000);
        PORTD=0;
        __delay_ms(1000);
    
    
       /* for(int k=0;k<=23;k++){
            setCursor(1,4){
            sprintf(horas,"%02u",k)
            print("horas");
                for(int m=0;m<=59;m++){
                    setCursor(7,1);
                    sprint(minut,"%02u",m);
                    print("minut");
                    for(int s=0;s<=59;s++){
                        setCursor(7,1);
                        sprint(segun,"%02u",s);
                        print("segun");
                    }
                    if(PORTBbits.RB4==1){
                        while PORTBbits.RB4==1;
                        k++;
                        setCursor(1,4){
                        sprintf(horas,"%02u",k)
                        print("horas");
                    }
                    __delay_ms(200);
                }
                
                
            }
        }*/        
    }
    
    return (EXIT_SUCCESS);
}




void __interrupt() first_int(void){
    cont++;
    PORTA=cont;
    INTCONbits.INT0IF=0;//YA SUCEDIO HAY Q BAJARLO OTRA VEZ
    
}
void conf(void){
    
    TRISBbits.RB0=1;//ENTRADA
    INTCONbits.INT0IE=1;//INTCON ES UN REGISTRO Y EL INTIE HABILITA INTERRUPCIONES
    INTCONbits.INT0IF=0;//LA BANDERA PA ABAJO,AUN NO SUCEDE LA interrupcion
    INTCON2bits.INTEDG0=0;//FLANCO DESCENDENTE
    INTCONbits.GIE=1;
}

void oscilador(void){
    OSCCON=0X40;
    OSCCON2=0X00;
}
