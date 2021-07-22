#include "EUSART.h"
#define _XTAL_FREQ 8000000

void serial_begin(long baudios){
    
    //configurar los baudios
    TRISCbits.RC6=0;//SALIDA TX
    TRISCbits.RC7=1;//ENTRADA RX
    BAUDCONbits.BRG16=0;//conf a 16 u 8 bits
    TXSTAbits.BRGH=0; //BAJA VELOCIDAD segun la tabla
    TXSTAbits.SYNC=0; //asincrono    
    SPBRG=(unsigned char)(((_XTAL_FREQ/baudios)/64)-1);
    RCSTAbits.SPEN=1; //Habilitar en serie
    
    //CONFIGURAR TX
    TXSTAbits.TX9=0; //UNA TRANSMISION DE 8BITS
    TXSTAbits.TXEN=1;
    
    //CONFIGURAR RX
    RCSTAbits.RC9=0; //UNA TRANSMISION DE 8BITS
    RCSTAbits.CREN=1;
}

void serial_print(char caracter){
    while(TXSTAbits.TRMT==0);//EL TRMT nos indica si el registro esta lleno o no
    
    TXREG1=caracter;
}

void serial_trama(char data[]){

    for (int k=0;data[k]!='\0';k++){
        
        serial_print(data[k]);    
    }
}

char serial_read(void){
    return RCREG1;
}