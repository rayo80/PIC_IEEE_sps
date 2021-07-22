

#include "mcc_generated_files/mcc.h"
#include "LCD.h"


char segun[3];
char minut[3];
char horas[3];


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    begin();
    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    TRISD=0;
    ANSELD=0;
    TRISE=0;
    setCursor(3,2);
    print("hola");
   

    while (1)
    {      
        __delay_ms(1000);
        cont++;
        if(cont==60){
            cont=0;
            cont1++;           
        }
        if(cont1==60){
            cont1=0;
            cont2++;           
        } 
        if(cont2==60){
            cont2=0;           
        }
        
        sprintf(segun,"%02u",cont); 
        sprintf(minut,"%02u",cont1);
        sprintf(horas,"%02u",cont2);
        setCursor(5,3);
        print(horas);
        setCursor(8,3);
        print(minut);
        setCursor(11,3);
        print(segun);

    }
}
