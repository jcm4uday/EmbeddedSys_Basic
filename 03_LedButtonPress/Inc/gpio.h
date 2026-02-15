#include <stdint.h>
#include "stm32f4xx.h"

typedef enum{
    INPUT = 0,
    OUTPUT = 1
}ModeType_t;

#define OFFST_ONE   1U
#define OFFSET_16   16U

void configureGpioAClk(void);
void configureGpioDClk(void);
void setGpioMode(GPIO_TypeDef* gpioPort, uint8_t pinNumber, ModeType_t setMode);
void gpioOutputSetReset(GPIO_TypeDef* gpioPort, uint8_t pinNumber, FlagStatus setResetVar);
uint8_t getGpioPinData(GPIO_TypeDef* gpioPort, uint8_t pinNumber);

