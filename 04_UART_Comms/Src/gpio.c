/*To define top level functions to configure GPIO pins as input/output set/reset*/
#include "gpio.h"
#include <stdint.h>


void configureGpioAClk(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

}

void configureGpioDClk(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

}

void setGpioMode(GPIO_TypeDef* gpioPort, uint8_t pinNumber, ModeType_t setMode)
{
    /*Set the mask*/
    uint32_t tempModePos = 0U;
    uint32_t tempModeMask = 0U;

    tempModePos = (pinNumber << OFFST_ONE);     /* Multiply by 2 as each pin takes two bits in ModeR register*/

    /*set positional masks for relevant two bits*/
    tempModeMask = (0x3U << tempModePos); /* set mask 11 in the position specified*/

    /*Clear the pin mode register bits. By default input state*/
    gpioPort->MODER &= ~(tempModeMask);

    /*Set LSB of relevant bits 01 that makes output mode*/
    if(setMode != 0)
    {
        gpioPort->MODER |= (OFFST_ONE << tempModePos);
    }
}

void gpioOutputSetReset(GPIO_TypeDef* gpioPort, uint8_t pinNumber, FlagStatus setResetVar)
{
    if(setResetVar == 0)
    {
         gpioPort->BSRR |=  (OFFST_ONE << (pinNumber + OFFSET_16)); /*Reset*/
    }
    else 
    {
        gpioPort->BSRR |=  (OFFST_ONE << (pinNumber));  /*Set*/
    }
}

uint8_t getGpioPinData(GPIO_TypeDef* gpioPort, uint8_t pinNumber)
{
    uint8_t readPinValue = 0U;
    /*Setup mask*/
    readPinValue = (gpioPort->IDR & ((uint32_t)OFFST_ONE << pinNumber));   /* set the right position of 32bit position of the pin status*/

    return readPinValue;
}