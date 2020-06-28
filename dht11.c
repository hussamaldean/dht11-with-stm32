#include "dht11.h"
#include "stdbool.h"
#include "stdio.h"
char data[8];
uint8_t bits[5];
uint8_t cnt = 7;
uint8_t idx = 0;
uint8_t sum;
int Humidity,Temperature;
//dht data pin is connected to PA0
uint16_t zz;
void dht11_init(void){
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
delay_init();
//delay_us_Init();
}



float update_dht11(void){
 bits[0]=0;bits[1]=0;bits[2]=0;bits[3]=0;bits[4]=0;
 cnt = 7;
 idx = 0;
GPIOA->MODER|=(1<<2);
GPIOA->OTYPER|=(1<<1);
GPIOA->ODR&=~(1<<1);
delayuS(30000);
GPIOA->ODR=(1<<1);
delayuS(40);
RCC->AHB1ENR&=~RCC_AHB1ENR_GPIOAEN;
GPIOA->MODER|=0x00;
//GPIOA->PUPDR|=1;
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
zz=0;
while(!(GPIOA->IDR&0x02)){sprintf(data,"here3"); zz++; delayuS(1);
			if(zz>15000){return -2;}}
zz=0;
while((GPIOA->IDR&0x02)){sprintf(data,"here4"); zz++; delayuS(1);
			if(zz>15000){return -2;}}
for (int i=0; i<40; i++)
  {
   zz=0;
    while(!(GPIOA->IDR&0x02)){sprintf(data,"here1"); zz++; delayuS(1);
			if(zz>15000){return -2;}
		}
		zz=0;
    while(GPIOA->IDR&0x02){sprintf(data,"here2");zz++; delayuS(1);if(zz>15000){return -2;}}
    if (zz > 20) {bits[idx] |= (1 << cnt);}
    if (cnt == 0)
    {
      cnt = 7; 
      idx++;
    }
    else cnt--;
  }
	 Humidity    = bits[0];
	 Temperature = bits[2];
	 sum = bits[0] + bits[2];
   if (bits[4] != sum){return -1;}
	return 0;
}