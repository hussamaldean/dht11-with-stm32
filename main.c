#include "delay.h"

#include "dht11.h"
int report;


void delayms(int delayms){
SysTick->LOAD=168000-1;
	SysTick->VAL=0;
	SysTick->CTRL=0x5;
		for (int i=0;i<delayms;i++)
		{
			while(!(SysTick->CTRL &0x10000)){}
		}
	SysTick->CTRL=0;
	}




int main(void)
{
SystemCoreClockUpdate();	
//	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
//	GPIOA->MODER|=0x01;
dht11_init();
while(1)
{

//	
//GPIOA->ODR=(1<<0);
//delayuS(1);
//GPIOA->ODR&=~(1<<0);
//delayuS(1);	
	
	
report=update_dht11();
delayms(2000);

}



}