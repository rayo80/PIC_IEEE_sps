
#ifndef LCD_H
#define	LCD_H
#define _XTAL_FREQ 2000000UL

#include <xc.h> // include processor files - each processor file is guarded.  
#define E PORTEbits.RE2
#define RS PORTEbits.RE0
#define D7 PORTDbits.RD7
#define D6 PORTDbits.RD6
#define D5 PORTDbits.RD5
#define D4 PORTDbits.RD4

void busdata(char a);
void comando(char a);
void begin(void);
void setCursor(char x,char y);
void caracter(char x);
void print(char a[]);
void create(char a,char b,char c,char d,char e,char f,char g,char h,char i);
void writecaracter(char a);
void clear(void);
void home(void);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

