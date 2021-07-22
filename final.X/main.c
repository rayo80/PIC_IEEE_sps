
#include "mcc_generated_files/mcc.h"
#include "LCD.h"
#include "EUSART.h"
#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#include "EUSART.h"
//agregamos esta libreria
#include <string.h>
#define _XTAL_FREQ 8000000 //NOTA TBN SE CAMBIA EL OSCILADOR Y POR LO TANTO CAMBIA EL TIMMER

char hora[12];
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_PeripheralInterruptEnable();
    begin();
    ANSELC=0;
    serial_begin(9600);

    ocultarcursor();
    setCursor(5,2);
    print("LA HORA ES:");
    

    while (1)
    {
        sprintf(segun,"%02u",cont);//convierte a cadena
        sprintf(minut,"%02u",cont1);
        sprintf(horas,"%02u",cont2);
        
        setCursor(7,3);
        print(horas);
        setCursor(10,3);
        print(minut);
        setCursor(13,3);
        print(segun);
        setCursor(9,3);
        print(":");
        setCursor(12,3);
        print(":");
        

       
        serial_trama(horas);
        serial_print(':');
        serial_trama(minut);
        serial_print(':');       
        serial_trama(segun);
        serial_trama("\n\r");
        __delay_ms(400);
                    
    }
}
/**
 End of File
*/