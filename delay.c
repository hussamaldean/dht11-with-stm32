#include "delay.h"
volatile uint64_t x;
volatile uint32_t current;
volatile uint64_t z;
void delay_init(void)
{
RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;  /*Enable TIM3 clock*/
	TIM3->PSC =2;  /* 16 000 000 /160 = 100 000*/
	TIM3->ARR = 55999;  /* 100 000 /100 = 1000*/
	TIM3->CNT =0;
	TIM3->CR1 =1;

}
void delay(uint32_t ms){


	
	for(int i =0;i<ms;i++){
	
		 while(!(TIM3->SR & 1)){}   /*wait for UIF set*/
			 TIM3->SR &= ~1;
			 
	}
	
	
}


void delayuS(uint32_t ms){	
uint32_t uSecVar = ms;
	uSecVar = uSecVar* ((SystemCoreClock/9999999*2));
	while(uSecVar--);
	
}
