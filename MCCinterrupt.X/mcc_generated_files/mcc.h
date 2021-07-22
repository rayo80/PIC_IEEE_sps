

#ifndef MCC_H
#define	MCC_H

#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "interrupt_manager.h"
#include "ext_int.h"


int cont=0;//SEGUNDOS
int cont1=0;
int cont2=0;


void SYSTEM_Initialize(void);


void OSCILLATOR_Initialize(void);

#endif	/* MCC_H */
/**
 End of File
*/