
#include <xc.h>
#include "tmr0.h"

/**
  Section: Global Variables Definitions
*/

void (*TMR0_InterruptHandler)(void);

volatile uint16_t timer0ReloadVal;

/**
  Section: TMR0 APIs
*/


void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface

    //Enable 16bit timer mode before assigning value to TMR0H
    T0CONbits.T08BIT = 0;

    // TMR0H 11; 
    TMR0H = 0x0B;

    // TMR0L 219; 
    TMR0L = 0xDB;

	
    // Load TMR0 value to the 16-bit reload variable
    timer0ReloadVal = (uint16_t)((TMR0H << 8) | TMR0L);

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);

    // T0PS 1:8; T08BIT 16-bit; T0SE Increment_hi_lo; T0CS FOSC/4; TMR0ON enabled; PSA assigned; 
    T0CON = 0x94;//ACA SE HACE UN CAMBIO DE 0X92 A 0X94  AHORA ES PRES 1:32 PUES EL OSCILADOR SE DIVIDO ENTRE 4
}



void TMR0_ISR(void)
{

    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    // reload TMR0
    // Write to the Timer0 register
    TMR0H = timer0ReloadVal >> 8;
    TMR0L = (uint8_t) timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
}


void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}

/**
  End of File
*/