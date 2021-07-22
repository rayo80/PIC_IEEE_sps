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
void menu_principal();
void menu_glucosa();
void menu_historial();
void menu_glucosa();
void oscilador(void);

void conf(void);
int cont;
int a=2;

void seleccion_up(int a);
void seleccion_down(int a);




int main(int argc, char** argv) {
     
    conf();
    oscilador();
    ANSELD=0;
    ANSELE=0;
    ANSELA=0;
    ANSELB=0;
    
    TRISD=0;
    TRISE=0;
    TRISA=1;
    TRISB=0;
    
    begin();
    create(1,0x08,0x0C,0x0E,0x0F,0x0E,0x0C,0x08,0x00);
    create(2,0x0E,0x0E,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F);
    
    menu_principal();
    ocultarcursor();
    seleccion_down(a);
      
    while(1){
        if (PORTAbits.RA1==1){ 
            while(PORTAbits.RA1==1);
            a++;
            if(a>4){
                a=4;
                seleccion_down(a);
            }
            else if(a<2){
                a=2;
                seleccion_down(a);
            }
            seleccion_down(a);
        }
        if (PORTAbits.RA0==1){ 
            while(PORTAbits.RA0==1);
            a--;
            if(a>4){
                a=4;
                seleccion_up(a);
            }
            else if(a<2){
                a=2;
                seleccion_up(a);
            }
            seleccion_up(a);
        }
        
    }
    return (EXIT_SUCCESS);
}
void oscilador(void){
    OSCCON=0X40;
    OSCCON2=0X00;
}

void conf(void){
    TRISBbits.RB0=1;//ENTRADA
    INTCONbits.INT0IE=1;//INTCON ES UN REGISTRO Y EL INTIE HABILITA la 1ra INTERRUPCION
    INTCONbits.INT0IF=0;//LA BANDERA PA ABAJO,AUN NO SUCEDE LA interrupcion
    INTCON2bits.INTEDG0=0;//FLANCO DESCENDENTE
    INTCONbits.GIE=1;
    //segunda interrupcion
    INTCON3bits.INT1IE=0;//SE DESHABILITA INTERRUPCION
    INTCON3bits.INT1IF=0;//LA BANDERA PA ABAJO,AUN NO SUCEDE LA interrupcion
    INTCON2bits.INTEDG1=0;//FLANCO DESCENDENTE
}

void menu_principal(){   
    setCursor(2,1);
    print("MENU");
    setCursor(15,1);
    writecaracter(2);
    print("%100");
    __delay_ms(100);
    setCursor(2,2);
    print("GLUCOSA");
    __delay_ms(100);
    setCursor(2,3);
    print("DOSIS");
    __delay_ms(100);
    setCursor(2,4);
    print("HISTORIAL");   
}

void menu_dosis(){
    setCursor(2,1);
    print("DOSIS");
    __delay_ms(100);
    setCursor(2,2);
    print("PERSONA");
    __delay_ms(100);
    setCursor(2,3);
    print("CANTIDAD");
    __delay_ms(100);
    setCursor(2,4);
    print("CONFIRMAR");
}
void menu_glucosa(){
    setCursor(2,1);
    print("GLUCOSA");
    __delay_ms(100);
    setCursor(2,2);
    print("PROBLEMAS");
    __delay_ms(100);
    setCursor(2,3);
    print("CANTIDAD");
    __delay_ms(100);
    setCursor(2,4);
    print("CONFIRMAR");
}
void menu_historial(){
    setCursor(2,1);
    print("HISTORIAL");
    __delay_ms(100);
    setCursor(2,2);
    print("REVISION 1");
    __delay_ms(100);
    setCursor(2,3);
    print("REVISION 2");
    __delay_ms(100);
    setCursor(2,4);
    print("REVISION 3");
}


void seleccion_down(a){
    setCursor(1,a-1);
    print(" ");
    setCursor(1,a);
    writecaracter(1);    
}
void seleccion_up(a){
    setCursor(1,a+1);
    print(" ");
    setCursor(1,a);
    writecaracter(1); 
}
void __interrupt() first_int(void){
    if(INTCONbits.INT0IF==1){
        if(a==2){
            clear();
            menu_glucosa();
            seleccion_up(2);
            __delay_ms(200);
        }
        else if(a==3){
            clear();
            menu_dosis();
            seleccion_up(2);
            __delay_ms(200);
        }
        else if(a==4){
            clear();
            menu_historial();
            seleccion_up(2);
            __delay_ms(200);
        }
        INTCONbits.INT0IF=0;//FLAG DOWN
        INTCONbits.INT0IE=0;//SE DESACTIVA ESTA INTERRUPCION
        INTCON3bits.INT1IE=1;//HABILITA LA SEGUNDA
        a=2;

    }
    if(INTCON3bits.INT1IF==1){
        __delay_ms(100);
        clear();

        menu_principal();
        seleccion_up(2);
        
        INTCON3bits.INT1IF=0;//flag down
        INTCON3bits.INT1IE=0;//DESACTIVAMOS ESTA INTERRUPCION
        INTCONbits.INT0IE=1;//habilitamos la PRIMERA

        a=2;
    }
}
