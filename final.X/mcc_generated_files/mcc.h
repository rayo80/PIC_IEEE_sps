
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
#include "tmr0.h"

int cont=0,cont1=0,cont2=0;
char segun[4],minut[4],horas[4];



void SYSTEM_Initialize(void);

void OSCILLATOR_Initialize(void);

#endif	/* MCC_H */
/**
 End of File
*/