/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F45K50
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set A0 aliases
#define A0_TRIS                 TRISAbits.TRISA0
#define A0_LAT                  LATAbits.LATA0
#define A0_PORT                 PORTAbits.RA0
#define A0_ANS                  ANSELAbits.ANSA0
#define A0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define A0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define A0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define A0_GetValue()           PORTAbits.RA0
#define A0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define A0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define A0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define A0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set A1 aliases
#define A1_TRIS                 TRISAbits.TRISA1
#define A1_LAT                  LATAbits.LATA1
#define A1_PORT                 PORTAbits.RA1
#define A1_ANS                  ANSELAbits.ANSA1
#define A1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define A1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define A1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define A1_GetValue()           PORTAbits.RA1
#define A1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define A1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define A1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define A1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set A2 aliases
#define A2_TRIS                 TRISAbits.TRISA2
#define A2_LAT                  LATAbits.LATA2
#define A2_PORT                 PORTAbits.RA2
#define A2_ANS                  ANSELAbits.ANSA2
#define A2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define A2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define A2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define A2_GetValue()           PORTAbits.RA2
#define A2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define A2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define A2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set A3 aliases
#define A3_TRIS                 TRISAbits.TRISA3
#define A3_LAT                  LATAbits.LATA3
#define A3_PORT                 PORTAbits.RA3
#define A3_ANS                  ANSELAbits.ANSA3
#define A3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define A3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define A3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define A3_GetValue()           PORTAbits.RA3
#define A3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define A3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define A3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define A3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set A4 aliases
#define A4_TRIS                 TRISAbits.TRISA4
#define A4_LAT                  LATAbits.LATA4
#define A4_PORT                 PORTAbits.RA4
#define A4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define A4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define A4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define A4_GetValue()           PORTAbits.RA4
#define A4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define A4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set A5 aliases
#define A5_TRIS                 TRISAbits.TRISA5
#define A5_LAT                  LATAbits.LATA5
#define A5_PORT                 PORTAbits.RA5
#define A5_ANS                  ANSELAbits.ANSA5
#define A5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define A5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define A5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define A5_GetValue()           PORTAbits.RA5
#define A5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define A5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define A5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define A5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set A6 aliases
#define A6_TRIS                 TRISAbits.TRISA6
#define A6_LAT                  LATAbits.LATA6
#define A6_PORT                 PORTAbits.RA6
#define A6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define A6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define A6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define A6_GetValue()           PORTAbits.RA6
#define A6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define A6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set A7 aliases
#define A7_TRIS                 TRISAbits.TRISA7
#define A7_LAT                  LATAbits.LATA7
#define A7_PORT                 PORTAbits.RA7
#define A7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define A7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define A7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define A7_GetValue()           PORTAbits.RA7
#define A7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define A7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set D0 aliases
#define D0_TRIS                 TRISDbits.TRISD0
#define D0_LAT                  LATDbits.LATD0
#define D0_PORT                 PORTDbits.RD0
#define D0_ANS                  ANSELDbits.ANSD0
#define D0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define D0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define D0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define D0_GetValue()           PORTDbits.RD0
#define D0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define D0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define D0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define D0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set D1 aliases
#define D1_TRIS                 TRISDbits.TRISD1
#define D1_LAT                  LATDbits.LATD1
#define D1_PORT                 PORTDbits.RD1
#define D1_ANS                  ANSELDbits.ANSD1
#define D1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define D1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define D1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define D1_GetValue()           PORTDbits.RD1
#define D1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define D1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define D1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define D1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set D2 aliases
#define D2_TRIS                 TRISDbits.TRISD2
#define D2_LAT                  LATDbits.LATD2
#define D2_PORT                 PORTDbits.RD2
#define D2_ANS                  ANSELDbits.ANSD2
#define D2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define D2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define D2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define D2_GetValue()           PORTDbits.RD2
#define D2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define D2_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define D2_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set D3 aliases
#define D3_TRIS                 TRISDbits.TRISD3
#define D3_LAT                  LATDbits.LATD3
#define D3_PORT                 PORTDbits.RD3
#define D3_ANS                  ANSELDbits.ANSD3
#define D3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define D3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define D3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define D3_GetValue()           PORTDbits.RD3
#define D3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define D3_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define D3_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISDbits.TRISD4
#define D4_LAT                  LATDbits.LATD4
#define D4_PORT                 PORTDbits.RD4
#define D4_ANS                  ANSELDbits.ANSD4
#define D4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define D4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define D4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define D4_GetValue()           PORTDbits.RD4
#define D4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define D4_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISDbits.TRISD5
#define D5_LAT                  LATDbits.LATD5
#define D5_PORT                 PORTDbits.RD5
#define D5_ANS                  ANSELDbits.ANSD5
#define D5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define D5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define D5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define D5_GetValue()           PORTDbits.RD5
#define D5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define D5_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISDbits.TRISD6
#define D6_LAT                  LATDbits.LATD6
#define D6_PORT                 PORTDbits.RD6
#define D6_ANS                  ANSELDbits.ANSD6
#define D6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define D6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define D6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define D6_GetValue()           PORTDbits.RD6
#define D6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define D6_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISDbits.TRISD7
#define D7_LAT                  LATDbits.LATD7
#define D7_PORT                 PORTDbits.RD7
#define D7_ANS                  ANSELDbits.ANSD7
#define D7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define D7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define D7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define D7_GetValue()           PORTDbits.RD7
#define D7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define D7_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/