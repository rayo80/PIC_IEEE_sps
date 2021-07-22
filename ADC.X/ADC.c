#include "ADC.h"
int conversion;

void ADC_begin(void){
    ANSELAbits.ANSA0=1;
    TRISAbits.RA0=1;
    ANSELBbits.ANSB0=1;
    TRISBbits.RB0=1;
    ANSELCbits.ANSC2=1;
    TRISCbits.RC2=1;
    
    
    ADCON0bits.CHS=0b0000;//seleccion del puerto A0 SEGUN EL DATA
    ADCON1bits.PVCFG0=0b00;//VALOR DE REFERENCIA ALTO
    ADCON1bits.NVCFG1=0b00;//VALOR DE REFERENCIA BAJO
    
    ADCON2bits.ADCS=0b100; //0.5us *4
    ADCON2bits.ACQT=0b010; //2us es nuestro tad pero el minimo es 7.5 us segun lo vimos en el datashet
    ADCON2bits.ADFM=1;// JUSTIFICADO a la derecha
    ADCON0bits.ADON=1;//darle on    
}

unsigned int analogRead(char canal){
    ADCON0bits.CHS=canal;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);//nota esto es muy importante ,pues asegura que la conversionse realice con exito dandole tiempo
    conversion=ADRESH<<8;
    conversion|=ADRESL;
    return conversion;
}