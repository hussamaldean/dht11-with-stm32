#ifndef __dht11__H

#define __dht11__H
#include "stm32f4xx.h"                  // Device header
#include "delay.h"
void dht11_init(void);
float update_dht11(void);



#endif

