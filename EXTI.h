#ifndef __EXTI_H
#define __EXTI_H
#include "type.h"
#include "AFIO.h"
#include "GPIO.h"


#define EXTI_RISING_MODE	0x00
#define EXTI_FALLING_MODE	0x01
#define EXTI_BOTH_MODE		0x02


#define NVIC_ISER0  *((uint32_t *)(0xE00E100UL))
#define NVIC_ISER1  *((uint32_t *)(0xE00E104UL))
typedef struct{
	__32BIT IMR;
	__32BIT EMR;
	__32BIT RTSR;
	__32BIT FTSR;
	__32BIT SWIER;
	__32BIT PR;
}EXTI_Typedef;

#define EXTI ((volatile EXTI_Typedef*) (0x40010400UL))


void EXTI0_IRQHandler(void);
uint8_t get_Pin_number(uint16_t gpio_pin);
void EXTI_Init(uint16_t gpio_pin, GPIO_typedef *port, uint8_t type);

#endif

