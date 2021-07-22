
#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    RCONbits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // Interrupt INT0I has no priority bit. It will always be called from the High Interrupt Vector


    // IOCI - low priority
    INTCON2bits.IOCIP = 0;    

}

void __interrupt() INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(INTCONbits.INT0IE == 1 && INTCONbits.INT0IF == 1)
    {
        cont2++;

        INT0_ISR();
        
    }
    else
    {
        //Unhandled Interrupt
    }
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void)
{
    // interrupt handler
    if(INTCONbits.IOCIE == 1 && INTCONbits.IOCIF == 1)
    {
        if (PORTBbits.RB4==1){
            while(PORTBbits.RB4==1);
            cont2--;

        }
        PIN_MANAGER_IOC();
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
