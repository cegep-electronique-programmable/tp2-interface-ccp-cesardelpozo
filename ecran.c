#include "ecran.h"
#include "mcc_generated_files/eusart1.h"

void ecranAllume(void){
    EUSART1_Write(0xFE);
    EUSART1_Write(0x41);
}

void ecranEteint(void){
    EUSART1_Write(0xFE);
    EUSART1_Write(0x42);
}

void curseurPosition(int position){
    EUSART1_Write(0xFE);
    EUSART1_Write(0x45);
    EUSART1_Write(position);
}

void videEcran(void){
    EUSART1_Write(0xFE);
    EUSART1_Write(0x51);
}

void ecrireCaractere(char caractere){
    EUSART1_Write(caractere);
}

void curseurClignoteON(void){
    EUSART1_Write(0xFE);
    EUSART1_Write(0x4B);
}

void curseurClignoteOFF(void){
    EUSART1_Write(0xFE);
    EUSART1_Write(0x4C);
}