#ifndef __delay__H__
#define __delay__H__
#include "stm32f4xx.h"                  // Device header
#include <stdint.h>
void delay(uint32_t ms);
void delayuS(uint32_t ms);
void delay_init(void);
#endif

