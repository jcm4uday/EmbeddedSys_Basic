#include <stdint.h>


/* GPIO_TypeDef structure definition */
struct GPIO_Typedef{
     volatile uint32_t MODER;       /*offset 0x00U*/
     volatile uint32_t OTYPER;      /*offset 0x04U*/
     volatile uint32_t OSPEEDR;     /*offset 0x08U*/
     volatile uint32_t PUPDR;       /*offset 0x0CU*/
     volatile uint32_t IDR;         /*offset 0x10U*/
     volatile uint32_t ODR;         /*offset 0x14U*/
     volatile uint32_t BSRR;        /*offset 0x18U*/
     volatile uint32_t LCKR;        /*offset 0x1CU*/
     volatile uint32_t AFRL;        /*offset 0x20U*/
     volatile uint32_t AFRH;        /*offset 0x24U*/

};

/* RCC_Typedef structure definition */
typedef struct{
     volatile uint32_t RCC_Buffer[12];
     volatile uint32_t RCC_AHB1ENR;     /*offset 0x30U*/
}RCC_Typedef;

/* setting up base address of RCC and GPIOA*/
#define RCC_BASE_ADDR 0x40023800U
#define GPIOA_BASE_ADDR 0x40020000U
#define GPIOD_BASE_ADDR 0x40020C00U

/* define pointers for RCC and GPIOD*/
#define RCC ((RCC_Typedef*)RCC_BASE_ADDR)
#define GPIOD ((struct GPIO_Typedef*)GPIOD_BASE_ADDR)

/* RCC for GPIOD*/
#define RCC_GPIODEN (1 << 3U)

/* Led pin 12 mask*/
#define LED12   (1 << 12U)



