
#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#include "configuracion.h"
#include "LCD.h"
#include "ADC.h"
#define _XTAL_FREQ 2000000

void oscilador(void);
void registros(void);

char valor[6];
int pot=0; //potenciometro
//PARTE2
char valor1[6],valor2[6];
int pot1=0,pot2=0;

int main(int argc, char** argv) {
    
    oscilador();
    registros();
    
    begin();
    ADC_begin();

    setCursor(2,1);
    __delay_ms(5000);
    print("HOLA");
    while(1){
        pot=analogRead(adc_A0);        
        pot1=analogRead(adc_B0);
        pot2=analogRead(adc_C2);
        
        sprintf(valor,"%4.1u",pot);
        sprintf(valor1,"%4.1u",pot1);
        sprintf(valor2,"%4.1u",pot2);
        
        setCursor(2,2);
        print(valor);
        setCursor(2,3);
        print(valor1);
        setCursor(2,4);
        print(valor2);
               /*
        ADCON0bits.CHS=0;
        //ahora falta el go/done para empezar la conversion
        ADCON0bits.GO_DONE=1;       
        //pot=ADRESH|ADRESL; RECORDAR QUE ESTO NO ES POSIBLE PUES TODOS LOS REGISTROS SON DE 16 BITS
        pot=ADRESH<<8;
        pot|=ADRESL;
        sprintf(valor,"%4.1u",pot);
        setCursor(2,2);
        print(valor);*///sin libreria
        
        
    }

   return (EXIT_SUCCESS);
}

void oscilador(void){
    OSCCON=0x40;
    OSCCON2=0x00;
}
void registros(void){
    ANSELD=0;
    ANSELE=0;
    TRISD=0;
    TRISE=0;
    //CONF DE NUESTRO CANAL ANALOGICO
   /* ANSELAbits.ANSA0=1; //EN EL 4550 ERA ANDCON
    TRISAbits.RA0=1;
    
    ADCON0bits.CHS=0b0000;//seleccion del puerto A0 SEGUN EL DATA
    ADCON1bits.PVCFG0=0b00;//VALOR DE REFERENCIA ALTO
    ADCON1bits.NVCFG1=0b00;//VALOR DE REFERENCIA BAJO
    
    ADCON2bits.ADCS=0b100; //0.5us *4
    ADCON2bits.ACQT=0b010; //2us es nuestro tad pero el minimo es 7.5 us segun lo vimos en el datashet
    ADCON2bits.ADFM=1;// JUSTIFICADO a la derecha
    ADCON0bits.ADON=1;//darle on    */ //todo este bloque paso a la libreria
}