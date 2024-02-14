#include "mcc_generated_files/mcc.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    bool estado = 0; //variable para leer el estado del pin RB0
    bool anterior = 1; //variable que almacena el estado anterior del pin RB0
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:
    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        estado = IO_RB0_GetValue(); //leemos el pin RB0
        if(estado == 0 && anterior == 1){ //si se presiono el boton
            __delay_ms(5); //retardo para el rebote
            if(estado == 0){ // si se presiono el boton
                IO_RD0_Toggle(); //esta funcion invierte el estado del pin
                anterior = 0; //se presiono el boton
            }
        }else if(estado == 1 && anterior == 0){
            __delay_ms(5);
            if(estado == 1)
                anterior = 1;
        }
    }
}
