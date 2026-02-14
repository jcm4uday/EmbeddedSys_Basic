/*To define top level functions to configure GPIO pins as input/output set/reset*/
#include "stm32f4xx.h"

void configureGpioAClk(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

}

void configureGpioDClk(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

}