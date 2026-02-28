#include "uart.h"

/*Initialise UART peripheral*/
/*Clock config using RCC_APB1ENR set  bit17 to enable UART2 */
void configureUart2Clk(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

}

/*USART2_TX, USART2_RX on PA2 and PA3*/
// Done through GPIO settings

/*Configure baud rate for UART - 9600*/
/*USARTDIV = 42Mhz/(16* 9600) =>273.4375. Using Over8 as 0. Usart_BRR = 0x1117 mantissa is 0x111 and fraction 0d7*/
void configureUart2BaudRate(void)
{
    USART2->BRR = 0x1117;
}


/*Configure CR1 register to  
1. UART enable
2. Set word length to 8
3. Disable parity checking
4. Transmitter enable
5. Receiver enable */
void configureUart2Register(void)
{
    USART2->CR1 |= (USART_CR1_RE_Msk | USART_CR1_TE_Msk | USART_CR1_UE);
}

/*Receive a character from the console to uC*/
UartRxStatus_t uart2RxStatus(void)
{
    UartRxStatus_t rxStatus = NO_DATA;
    uint32_t tempRxStatus = 0;

    tempRxStatus = USART2->SR & USART_SR_RXNE;  /* Read status register RXNE value*/

    if(tempRxStatus == 1)
    {
        rxStatus = DATA_READY;
    }

    return rxStatus;
}

uint32_t uart2RxData(void)
{
    uint32_t rxData = 0;

    if(uart2RxStatus() == 1)
    {
        /*Read data register*/
        rxData = USART2->DR;
    }

    return rxData;
}

/*Send a character from the console to uC*/

/*Listen serial commands from the receiver*/

/*Setup commands
1. SET_FREQ 0dx\n
2. GET_STATUS */

/*Parse incoming frames matching to commands*/

/*Respond to commands*/