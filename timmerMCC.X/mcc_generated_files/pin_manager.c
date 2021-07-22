

#include "pin_manager.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x02;
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xC7;
    TRISD = 0x0E;

    /**
    ANSELx registers
    */
    ANSELD = 0x0E;
    ANSELC = 0xC4;
    ANSELB = 0x39;
    ANSELE = 0x02;
    ANSELA = 0x2F;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    INTCON2bits.nRBPU = 1;






   
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// Clear global Interrupt-On-Change flag
    INTCONbits.IOCIF = 0;
}

/**
 End of File
*/