#include "RCC.h"
// bat clock cua port A , B , C
void RCC_enable_portA(void){
	RCC->APB2ENR.BITS.IOPAEN =1;
}
void RCC_enable_portB(void){
	RCC->APB2ENR.BITS.IOPBEN =1;
}
void RCC_enable_portC(void){
	RCC->APB2ENR.BITS.IOPCEN =1;
}
