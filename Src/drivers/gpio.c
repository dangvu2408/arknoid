/*
 * gpio.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */


#include "drivers/gpio.h"

void GPIO_EnableAllClocks(void){
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA |
                         RCC_AHB1Periph_GPIOB |
                         RCC_AHB1Periph_GPIOC, ENABLE);
}
