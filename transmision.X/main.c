
#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#include "configuracion.h"
#include "EUSART.h"
#define _XTAL_FREQ 8000000


void oscilador(void);
int main(int argc, char** argv) {
    ANSELC=0;
    ANSELD=0;
    TRISD=0;
    oscilador();
    serial_begin(9600);
    
    while(1){
        
        //serial_trama("\r\nSEMPO");// \n \r tbn funcan aca
        if(serial_read()=='A'){
            PORTD=255;           
        }
        else{
            PORTD=0;
        }

    }
    return (EXIT_SUCCESS);
}

void oscilador(void){
    OSCCON=0x60; //se cambia a8MGHZ
    OSCCON2=0x00;
}
