#include <stdint.h>
#include "stm32f4xx.h"

typedef enum{
    NO_DATA = 0,
    DATA_READY = 1
} UartRxStatus_t;

void configureUart2Clk(void);
void configureUart2BaudRate(void);
void configureUart2Register(void);

/*Receive a character from the console to uC*/
UartRxStatus_t uart2RxStatus(void);

uint32_t uart2RxData(void);