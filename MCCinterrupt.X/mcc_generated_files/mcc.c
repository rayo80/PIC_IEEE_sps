

#include "mcc.h"


void SYSTEM_Initialize(void)
{

    INTERRUPT_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    EXT_INT_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; IDLEN disabled; IRCF 2MHz; 
    OSCCON = 0x40;
    // INTSRC INTRC_31_25KHz; PLLEN disabled; PRISD disabled; SOSCGO disabled; 
    OSCCON2 = 0x00;
}


/**
 End of File
*/
