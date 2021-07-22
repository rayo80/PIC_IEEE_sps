
#include <xc.h>
#include "ext_int.h"

void (*INT1_InterruptHandler)(void);
void (*INT2_InterruptHandler)(void);

void INT1_ISR(void)
{
    EXT_INT1_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT1_CallBack();    
}


void INT1_CallBack(void)
{
    // Add your custom callback code here
    if(INT1_InterruptHandler)
    {
        INT1_InterruptHandler();
    }
}

void INT1_SetInterruptHandler(void (* InterruptHandler)(void)){
    INT1_InterruptHandler = InterruptHandler;
}

void INT1_DefaultInterruptHandler(void){
    // add your INT1 interrupt custom code
    // or set custom function using INT1_SetInterruptHandler()
}
void INT2_ISR(void)
{
    EXT_INT2_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT2_CallBack();    
}


void INT2_CallBack(void)
{
    // Add your custom callback code here
    if(INT2_InterruptHandler)
    {
        INT2_InterruptHandler();
    }
}

void INT2_SetInterruptHandler(void (* InterruptHandler)(void)){
    INT2_InterruptHandler = InterruptHandler;
}

void INT2_DefaultInterruptHandler(void){
    // add your INT2 interrupt custom code
    // or set custom function using INT2_SetInterruptHandler()
}

void EXT_INT_Initialize(void)
{
    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    EXT_INT1_InterruptFlagClear();   
    EXT_INT1_fallingEdgeSet();    
    // Set Default Interrupt Handler
    INT1_SetInterruptHandler(INT1_DefaultInterruptHandler);
    EXT_INT1_InterruptEnable();      

    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    EXT_INT2_InterruptFlagClear();   
    EXT_INT2_fallingEdgeSet();    
    // Set Default Interrupt Handler
    INT2_SetInterruptHandler(INT2_DefaultInterruptHandler);
    EXT_INT2_InterruptEnable();      

}

