#include "mcc_generated_files/mcc.h"

void main(void)
{
    uint16_t data; //variable que almacenara la lectura del ADC
    float voltaje; //variable float que tendra el resultado final de la lectura ya convertido a voltaje
    // Initialize the device
    SYSTEM_Initialize();
    ADC_SelectChannel(channel_AN10); //seleccionamos el canal AN10 como canal a usar por el ADC

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
        ADC_StartConversion(); //iniciamos la conversion
        while(!ADC_IsConversionDone()); //esperamos a que termine la conversion
        data = ADC_GetConversionResult(); //guardamos la lectura en data
        voltaje = data * 5.0/1023; //realizo la conversion a voltaje
        printf("El voltaje es: %f v\n\r", voltaje); //imprimimos el resultado de la lectura por el terminal serie
        __delay_ms(100); //retardo de 100 ms
    }
}
