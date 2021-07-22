
#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    RCONbits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // TMRI - high priority
    INTCON2bits.TMR0IP = 1;


    // INT1I - low priority
    INTCON3bits.INT1IP = 0;    

    // INT2I - low priority
    INTCON3bits.INT2IP = 0;    

}

void __interrupt() INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1)
    {
        TMR0_ISR();//desbordamiento
        cont++;
        if(cont==60){
            cont=0;
            cont1++;
        }
        if(cont1==60){
            cont1=0;
            cont2++;
        }
        if(cont2==24){
            cont2=0;
            
        }
        PORTDbits.RD0=~PORTDbits.RD0;
    }
    else
    {
        //Unhandled Interrupt
    }
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void)
{
    // interrupt handler
    if(INTCON3bits.INT1IE == 1 && INTCON3bits.INT1IF == 1)
    {
        INT1_ISR();
        cont2++;
        if(cont2==61){
            cont2=0;
        }
    }
    else if(INTCON3bits.INT2IE == 1 && INTCON3bits.INT2IF == 1)
    {
        INT2_ISR();
        cont2--;
        if(cont2==-1){
            cont2=0;
        }
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
