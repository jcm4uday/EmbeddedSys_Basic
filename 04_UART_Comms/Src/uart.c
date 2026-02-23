/*Initialise UART peripheral*/
/*Clock config using RCC_APB1ENR set  bit5 to enable USART*/

/*USART2_TX, USART2_RX on PA2 and PA3*/

/*Configure baud rate for UART*/

/*Configure CR1 register to  
1. UART enable
2. Set word length to 8
3. Disable parity checking
4. Transmitter enable
5. Receiver enable */

/*Send and receive a character from the console to uC*/

/*Listen serial commands from the receiver*/

/*Setup commands
1. SET_FREQ 0dx\n
2. GET_STATUS */

/*Parse incoming frames matching to commands*/

/*Respond to commands*/