#include <stdint.h>
#include "stm32f4xx.h"

typedef enum{
    INPUT = 0,
    OUTPUT = 1,
    ALT_FUNC = 2,
    ANALOG = 3
}ModeType_t;

#define OFFST_ONE   1U
#define OFFST_TWO   2U
#define OFFST_THREE 3U
#define OFFSET_16   16U

void configureGpioAClk(void);
void configureGpioDClk(void);
void setGpioMode(GPIO_TypeDef* gpioPort, uint8_t pinNumber, ModeType_t setMode);
void gpioOutputSetReset(GPIO_TypeDef* gpioPort, uint8_t pinNumber, FlagStatus setResetVar);
uint8_t getGpioPinData(GPIO_TypeDef* gpioPort, uint8_t pinNumber);

