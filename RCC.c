#include "RCC.h"
// bat clock cua port A , B , C
void RCC_enable_portA(void){
	RCC->APB2ENR.BITS.IOPAEN =1;
	//RCC->APB2ENR.REG |= (1<<2);
}
void RCC_enable_portB(void){
	RCC->APB2ENR.BITS.IOPBEN =1;
}
void RCC_enable_portC(void){
	RCC->APB2ENR.BITS.IOPCEN =1;
}
// bật cái gì thì phải bật clock lên vd uart
//void enable_uart(void){RCC->APB2ENR.BITS.uSART1EN =1;}
void RCC_config_72Mhz(void){
	//enable HSE
	RCC->CR.BITS.HSEON =1;
	while (!RCC->CR.BITS.HSEON){

	}
	RCC->CFGR.BITS.PLLSRC =1;
	RCC->CFGR.BITS.PLLMUL = 7; // 0111 x9 PLL
	RCC->CR.BITS.PLLON =1;
	while(!RCC->CR.BITS.PLLRDY){}

	//AHB
	RCC->CFGR.BITS.HPRE =0;
	//APB1
	RCC->CFGR.BITS.PPRE1 = 4 ;// /2
	//APB2
	RCC->CFGR.BITS.PPRE2 = 0; // /1

	RCC->CFGR.BITS.SW =2;
	while(RCC->CFGR.BITS.SWS != 2){}


}
