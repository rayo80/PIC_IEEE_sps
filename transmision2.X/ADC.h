 
#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  
//DEFINO ETIQUETAS
#define adc_A0 0b00000
#define adc_B0 0b01100
#define adc_C2 0b01110



void ADC_begin(void);
unsigned int analogRead(char canal);// funcion que devuelve variable
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

