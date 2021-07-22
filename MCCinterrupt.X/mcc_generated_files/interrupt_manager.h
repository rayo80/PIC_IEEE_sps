

#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H

#define INTERRUPT_GlobalInterruptHighEnable() (INTCONbits.GIEH = 1)

#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH = 0)

#define INTERRUPT_GlobalInterruptLowEnable() (INTCONbits.GIEL = 1)


#define INTERRUPT_GlobalInterruptLowDisable() (INTCONbits.GIEL = 0)

#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)


#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)

void INTERRUPT_Initialize (void);

#endif  // INTERRUPT_MANAGER_H
/**
 End of File
*/
