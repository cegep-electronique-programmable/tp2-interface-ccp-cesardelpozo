/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F25K80
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "ecran.h"

void Capture_CallBack(uint16_t capturedValue);//Fonction lors de l'interruption
uint16_t gDuree;//Variable qui prends la quantité de steps fait par le timer 1 a chaque capture
bool front = 0;//Variable d'essai pour pouvoir changer si on veut une capture au front montant ou descendant

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();

    INTERRUPT_PeripheralInterruptEnable();

    CCP2_SetCallBack(Capture_CallBack);
    int periode;
    int tempshaut;
    
    while (1)
    {
        curseurPosition(0x00);//Partie du code pour afficher le temps d'une période
        periode = gDuree * (32.768 / 65536) * 1000;//Temps de la période divisé par le nombre de step du Timer 1 fois le nombre de step capturé fois 1000 pour le temps de la période en ms 
        printf("La periode: %dus\n\r", periode);
        
/*        curseurPosition(0x00);
        
        if(front == 1){  //Partie du code d'essai pour mesurer le temps haut. Ça n'a pas fonctionné
            tempshaut = gDuree * (32.768 / 65536) * 1000;
            printf("Temps haut: %dus\n\r", tempshaut);
            printf("gDuree: %d", gDuree); 
            CCP2CON = 0x04;
            PIR3bits.CCP2IF = 0;
        }
        else if(front == 0){
            CCP2CON = 0x05;
            PIR3bits.CCP2IF = 0;
        }*/
    }
}

void Capture_CallBack(uint16_t capturedValue)//Que faire lorsque qu'il y a une capture
    {
        gDuree = capturedValue;
        TMR1_Reload();
        front = ~front;
    }
/**
 End of File
*/