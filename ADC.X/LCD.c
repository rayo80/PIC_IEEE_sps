
#include "LCD.h"

void busdata(char a){
    if (a & 0x01){
        D4=1;   
    }
    else{
        D4=0;
    }
    if (a & 0x02){
        D5=1;   
    }
    else{
        D5=0;
    }
    if (a & 0x04){
        D6=1;   
    }
    else{
        D6=0;
    }
    if (a & 0x08){
        D7=1;   
    }
    else{
        D7=0;
    }
    
    
}
void comando(char a){
    E=0;
    E=1;
    //BUS DE DATOS
    busdata(a);
    __delay_ms(1);
    E=0;
}

void begin(void){
    comando(0x03);
    comando(0x03);
    comando(0x03);
    comando(0x02);
    comando(0x02);
    comando(0x08);
    comando(0x00);
    comando(0x08);
    comando(0x00);
    comando(0x01);
    comando(0x00);
    comando(0x0D);   
}

void setCursor(char x,char y){
    char m;
    char n;
    if(y==1){
        m=0x80 + x;
        n=(0x80 + x) >> 4;
        comando(n);
        comando(m);
    }
    if(y==2){
        m=0xC0 + x;
        n=(0xC0 + x) >> 4;
        comando(n);
        comando(m);
    }
    if(y==3){
        m=0x80 +20+ x;
        n=(0x80+20 + x) >> 4;
        comando(n);
        comando(m);
    }
    if(y==4){
        m=0xC0 +20+ x;
        n=(0xC0 + 20+ x) >> 4;
        comando(n);
        comando(m);
    }
}

void caracter(char a){
    char m,n;
    m=a>>4;
    n=a;
    RS=1;
    comando(m);
    comando(n);
    RS=0;
}

void print(char a[]){
    for (int k=0;a[k]!='\0';k++){
        caracter(a[k]);        
    }
}

void create(char a,char b,char c,char d,char e,char f,char g,char h,char i){
    if(a==1){
        comando(0x04);
        comando(0x00);
        RS=1;
        char m,n;
        m=b>>4;
        n=b;       
        comando(m);
        comando(n);
        m=c>>4;
        n=c;       
        comando(m);
        comando(n);
        m=d>>4;
        n=d;       
        comando(m);
        comando(n);
        m=e>>4;
        n=e;       
        comando(m);
        comando(n);
        m=f>>4;
        n=f;       
        comando(m);
        comando(n);
        m=g>>4;
        n=g;       
        comando(m);
        comando(n);
        m=h>>4;
        n=h;       
        comando(m);
        comando(n);
        m=i>>4;
        n=i;       
        comando(m);
        comando(n);
        RS=0;
        comando(0x00);
        comando(0x01);
        __delay_ms(100);
    }
    if(a==2){
        comando(0x04);
        comando(0x08);
        RS=1;
        char m,n;
        m=b>>4;
        n=b;       
        comando(m);
        comando(n);
        m=c>>4;
        n=c;       
        comando(m);
        comando(n);
        m=d>>4;
        n=d;       
        comando(m);
        comando(n);
        m=e>>4;
        n=e;       
        comando(m);
        comando(n);
        m=f>>4;
        n=f;       
        comando(m);
        comando(n);
        m=g>>4;
        n=g;       
        comando(m);
        comando(n);
        m=h>>4;
        n=h;       
        comando(m);
        comando(n);
        m=i>>4;
        n=i;       
        comando(m);
        comando(n);
        RS=0;
        comando(0x00);
        comando(0x01);
        __delay_ms(100);
    }
    
}


void writecaracter(char a){
    RS=1;
    comando(0x00);
    comando(a-1);
    RS=0;
}

void clear(void){
    comando(0x00);
    comando(0x01);
}

void home(void){
    comando(0x00);
    comando(0x02);
}

void ocultarcursor(void){
    comando(0x00);
    comando(0x0c);
}
