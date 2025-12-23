/*
 * led.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */


#include "periph/led.h"
#include "drivers/timebase.h"

void LED_Init(void){
  GPIO_InitTypeDef gi;
  gi.GPIO_Pin   = LED_PIN;
  gi.GPIO_Mode  = GPIO_Mode_OUT;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LED_GPIOx, &gi);
}

void LED_Blink(uint8_t times, uint16_t on_ms, uint16_t off_ms){
  for(uint8_t i = 0; i < times; i++){
    LED_On();  Delay_ms(on_ms);
    LED_Off(); Delay_ms(off_ms);
  }
}
