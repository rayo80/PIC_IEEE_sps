
#include "mcc_generated_files/mcc.h"
#include "LCD.h"


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_PeripheralInterruptEnable();
    begin();
    ocultarcursor();
    print("funcionando");
    

    while (1)
    {
        sprintf(segun,"%02u",cont);
        sprintf(minut,"%02u",cont1);
        sprintf(horas,"%02u",cont2);
        
        setCursor(7,2);
        print(horas);
        setCursor(10,2);
        print(minut);
        setCursor(13,2);
        print(segun);
        setCursor(9,2);
        print(":");
        setCursor(12,2);
        print(":");
    }
}
/**
 End of File
*/