#include "UART.h"
#include "GPIO.h"
#include "EXTI.h"

void UART1_Init(void){
	//PA9 : output AF PP
	GPIO_Config(GPIOA, GPIO_PIN_9, GPIO_MODE_AF_PP);
	//PA10 : INPUT Floating
	GPIO_Config(GPIOA, GPIO_PIN_10, GPIO_MODE_INPUT_FLOATING);
	//baudrate 9600 clock 8MHz
	USART1_BRR = 0x0341;
	USART1_CR1 |= (1<<13);
	USART1_CR1 |= (1<<3);
	USART1_CR1 |= (1<<2);
	NVIC_UART_EN();
}

void UART1_Sendchar(char c){
	while (!(USART1_SR &(1<<7)));

	USART1_DR = c;
}

void UART1_SengString(const char *str){
	while (*str){
		USART1_Sendchar(*str++);
	}
}
void UART1_EnableRxInterrupt(void){
	USART1_CR1 |= (1<<5);           // RXNEIE - cho phép tạo ngắt khi có dữ liệu tới
	NVIC_ISER1 |= (1<<(37-32));     // USART1_IRQn = 37 → nằm ở ISER1, bit vị trí 5
}
void USART1_IRQHandler(){
	if(USART1_SR & (1<<5)){

		char c = (char)(USART1_DR & (0xFF));
		UART1_Sendchar(c);
	}
}
